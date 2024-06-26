# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svereten <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 14:23:33 by svereten          #+#    #+#              #
#    Updated: 2024/06/26 17:07:45 by svereten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = pipex
DEV_NAME = pipex_dev
TESTS_NAME = pipex_tests

CC = cc

CFLAGS = -Wall -Wextra -Werror
DEV_CFLAGS = -g

INCLUDE = -I./include -I./libft/include
TESTS_INCLUDE = -I./test-include

LIBFT = ./libft/libft.a

LIBFT_DIR = libft
SRC_DIR = src
OBJ_DIR = obj

PIPEX_FILES = pipex \
			  env/env \
			  path/path \
			  state/state_feed \
			  state/state_init \
			  args/args_count
PIPEX_SRCS = ${PIPEX_FILES:%=${SRC_DIR}/%.c}
PIPEX_OBJS = ${PIPEX_FILES:%=${OBJ_DIR}/%.o}

SRCS_FILES = ${PIPEX_FILES} main
SRCS = $(SRCS_FILES:%=${SRC_DIR}/%.c)
OBJS = $(SRCS_FILES:%=${OBJ_DIR}/%.o)


DEV_FILES = dev/dev
DEV_SRCS = ${DEV_FILES:%=${SRC_DIR}/%.c}
DEV_OBJS = ${DEV_FILES:%=${OBJ_DIR}/%.o}


TESTS_FILES = ${PIPEX_FILES} \
			  tests_main \
			  args/tests_args_count
TESTS_SRCS = ${TESTS_FILES:%=${SRC_DIR}/%.c}
TESTS_OBJS = ${TESTS_FILES:%=${OBJ_DIR}/%.o}


ALL_OBJS = ${OBJS} ${DEV_OBJS} ${TESTS_OBJS}
OBJ_DIRS = $(sort $(dir ${ALL_OBJS}))

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT}
	${CC} ${CFLAGS} ${INCLUDE} $^ -o $@


dev: ${DEV_NAME}

${DEV_NAME}: ${OBJS} ${DEV_OBJS} ${LIBFT}
	${CC} ${CFLAGS} ${DEV_CFLAGS} ${INCLUDE} $^ -o $@


tests: ${TESTS_NAME}
	./${TESTS_NAME}

${TESTS_NAME}: ${TESTS_OBJS} ${PIPEX_OBJS} ${LIBFT}
	${CC} ${CFLAGS} ${DEV_CFLAGS} ${INCLUDE} ${TESTS_INCLUDE} $^ -o $@


${OBJ_DIR}/%.o: ${SRC_DIR}/%.c | ${OBJ_DIRS}
	${CC} ${CFLAGS} ${DEV_CFLAGS} ${INCLUDE} ${TESTS_INCLUDE} -c $< -o $@

${LIBFT}:
	${MAKE} -C ${LIBFT_DIR}

${OBJ_DIRS}:
	mkdir -p $@

norm:
	norminette ${PIPEX_SRC}

clean:
	rm -rf ${OBJ_DIR}
	${MAKE} clean -C ${LIBFT_DIR}

fclean: clean
	rm -rf ${NAME}
	rm -rf ${DEV_NAME}
	rm -rf ${TESTS_NAME}
	${MAKE} fclean -C ${LIBFT_DIR}

re: fclean all

.PHONY: all dev tests clean fclean re
