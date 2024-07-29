# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svereten <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 14:23:33 by svereten          #+#    #+#              #
#    Updated: 2024/07/29 19:10:10 by svereten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = pipex
DEV_NAME = pipex_dev

CC = cc

CFLAGS = -Wall -Wextra -Werror
DEV_CFLAGS = -g

INCLUDE = -I./include -I./libft/include

LIBFT = ./libft/libft.a

LIBFT_DIR = libft
SRC_DIR = src
OBJ_DIR = obj

FILES = main \
	 	env/env \
		path/path \
		state/state_feed \
		state/state_init \
		args/args_count \

SRCS = ${FILES:%=${SRC_DIR}/%.c}
OBJS = ${FILES:%=${OBJ_DIR}/%.o}

DEV_FILES = dev/dev
DEV_SRCS = ${DEV_FILES:%=${SRC_DIR}/%.c}
DEV_OBJS = ${DEV_FILES:%=${OBJ_DIR}/%.o}

OBJ_DIRS = $(sort $(dir ${OBJS}))

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT}
	${CC} ${CFLAGS} ${INCLUDE} $^ -o $@

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c | ${OBJ_DIRS}
	${CC} ${CFLAGS} ${DEV_CFLAGS} ${INCLUDE} ${TESTS_INCLUDE} -c $< -o $@

${LIBFT}:
	${MAKE} -C ${LIBFT_DIR}

${OBJ_DIRS}:
	mkdir -p $@
################################################################################
#
# Libunit variables
#
################################################################################

RUNNER_DIR = run
TESTS_DIR = tests

#RUNNERS = ${SRCS:%=${RUNNER_DIR}/%_tests}
RUNNERS = run/args/args_count_tests
#TESTS_OBJS = ${SRCS:%=${OBJS_DIR}/%_tests.o}
TESTS_OBJS = obj/args/args_count_tests.o

clean:
	rm -rf ${OBJ_DIR}
	${MAKE} clean -C ${LIBFT_DIR}

fclean: clean
	rm -rf ${NAME}
	rm -rf ${DEV_NAME}
	rm -rf ${TESTS_NAME}
	${MAKE} fclean -C ${LIBFT_DIR}

re: fclean all

#eval rules end here

dev: ${DEV_NAME}

${DEV_NAME}: ${OBJS} ${DEV_OBJS} ${LIBFT}
	${CC} ${CFLAGS} ${DEV_CFLAGS} ${INCLUDE} $^ -o $@

norm:
	norminette ${PIPEX_SRC}

################################################################################
#
# Libunit rules
#
################################################################################

${OBJS_DIR}/%.o: ${TESTS_DIR}/%.c | ${OBJ_DIRS}
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

runners: ${RUNNERS}

${RUNNER_DIR}/%: obj/%.o ${OBJS}
	@${MAKE} -C libunit ../$@

test: runners
	@./libunit/run_runners.sh

.PHONY: all dev tests clean fclean re
