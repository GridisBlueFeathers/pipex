# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svereten <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 14:23:33 by svereten          #+#    #+#              #
#    Updated: 2024/08/21 16:37:52 by svereten         ###   ########.fr        #
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

FILES = env/env \
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

################################################################################
#
# Libunit variables
#
################################################################################

LIBUNIT_INCLUDE = -I./libunit/include

RUNNER_DIR = run
TESTS_DIR = tests

#RUNNERS = ${SRCS:%=${RUNNER_DIR}/%_tests}
RUNNERS = run/args/args_count_tests \
		  run/args/args_split_tests 
#TESTS_OBJS = ${SRCS:%=${OBJS_DIR}/%_tests.o}
TESTS_OBJS = obj/args/args_count_tests.o

all: ${NAME}

${NAME}: ${OBJS} ${SRC_DIR}/main.o ${LIBFT}
	${CC} ${CFLAGS} ${INCLUDE} $^ -o $@

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c | ${OBJ_DIRS}
	${CC} ${CFLAGS} ${DEV_CFLAGS} ${INCLUDE} -c $< -o $@

${LIBFT}:
	${MAKE} -C ${LIBFT_DIR}

${OBJ_DIRS}:
	mkdir -p $@

clean:
	rm -rf ${OBJ_DIR}
	rm -rf ${RUNNER_DIR}
	${MAKE} clean -C ${LIBFT_DIR}

fclean: clean
	rm -rf ${NAME}
	rm -rf ${DEV_NAME}
	rm -rf ${RUNNER_DIR}
	${MAKE} fclean -C ${LIBFT_DIR}

re: fclean all

#eval rules end here

dev: ${DEV_NAME}

${DEV_NAME}: ${OBJS} ${DEV_OBJS} ${LIBFT}
	${CC} ${CFLAGS} ${DEV_CFLAGS} ${INCLUDE} $^ -o $@

norm:
	norminette ${SRCS}

################################################################################
#
# Libunit rules
#
################################################################################

${OBJ_DIR}/%.o: ${TESTS_DIR}/%.c | ${OBJ_DIRS}
	${CC} ${CFLAGS} ${INCLUDE} ${LIBUNIT_INCLUDE} -c $< -o $@

runners: ${RUNNERS}
	@echo ${RUNNERS}

${RUNNER_DIR}/%: ${OBJ_DIR}/%.o ${OBJS}
	${MAKE} -C libunit ../$@

test: runners
	@./libunit/run_runners.sh

.PHONY: all dev tests clean fclean re
