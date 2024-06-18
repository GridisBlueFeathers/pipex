# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svereten <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 14:23:33 by svereten          #+#    #+#              #
#    Updated: 2024/06/18 17:08:09 by svereten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC_FILES = main \
		   env/env \
		   path/path \
		   state/state_feed \
		   state/state_init \

SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft

SRCS = $(SRC_FILES:%=${SRC_DIR}/%.c)
OBJS = $(SRC_FILES:%=${OBJ_DIR}/%.o)

OBJ_DIRS = $(sort $(dir ${OBJS}))

INCLUDE = -I./include -I./libft/include

LIBFT = ./libft/libft.a

DEV_NAME = pipex_dev

DEV_CFLAGS = -g

DEV_FILES = dev/dev \

DEV_SRCS = ${DEV_FILES:%=${SRC_DIR}/%.c}
DEV_OBJS = ${DEV_FILES:%=${SRC_DIR}/%.c}

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT}
	${CC} ${CFLAGS} ${INCLUDE} $^ -o $@

dev: ${DEV_NAME}

${DEV_NAME}: ${OBJS} ${DEV_OBJS} ${LIBFT}
	${CC} ${CFLAGS} ${DEV_CFLAGS} ${INCLUDE} $^ -o $@

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c | ${OBJ_DIRS}
	${CC} ${CFLAGS} ${DEV_CFLAGS} ${INCLUDE} -c $< -o $@

${LIBFT}:
	${MAKE} -C ${LIBFT_DIR}

${OBJ_DIRS}:
	mkdir -p $@

norm:
	norminette ${SRCS}

clean:
	rm -rf ${OBJ_DIR}
	${MAKE} clean -C ${LIBFT_DIR}

fclean: clean
	rm -rf ${NAME}
	rm -rf ${DEV_NAME}
	${MAKE} fclean -C ${LIBFT_DIR}

re: fclean all

.PHONY: all clean fclean re
