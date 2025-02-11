# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svereten <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 14:23:33 by svereten          #+#    #+#              #
#    Updated: 2024/09/11 23:47:37 by svereten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror

INCLUDE = -I./include -I./libft/include

LIBFT = ./libft/libft.a

LIBFT_DIR = libft
SRC_DIR = src
OBJ_DIR = obj

FILES = main \
		env \
		path \
		panic \
		utils \
		state/state_feed \
		state/state_init \
		state/state_fd \
		cmd/cmd_process \
		cmd/cmd_exec \
		cmds \
		args/args \
		args/args_split \

OBJS = ${FILES:%=${OBJ_DIR}/%.o}

OBJ_DIRS = $(sort $(dir ${OBJS}))

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT}
	${CC} ${CFLAGS} ${INCLUDE} $^ -o $@

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c | ${OBJ_DIRS}
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

${LIBFT}:
	${MAKE} -C ${LIBFT_DIR}

${OBJ_DIRS}:
	mkdir -p $@

clean:
	rm -rf ${OBJ_DIR}
	${MAKE} clean -C ${LIBFT_DIR}

fclean: clean
	rm -rf ${NAME}
	${MAKE} fclean -C ${LIBFT_DIR}

re: fclean all

.PHONY: all clean fclean re
