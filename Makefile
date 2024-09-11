# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svereten <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 14:23:33 by svereten          #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2024/09/11 15:29:38 by svereten         ###   ########.fr        #
=======
#    Updated: 2024/09/11 16:07:44 by svereten         ###   ########.fr        #
>>>>>>> pre-eval
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
<<<<<<< HEAD

.PHONY: all dev clean fclean re
=======
	${MAKE} re -C ${LIBFT_DIR}

.PHONY: all clean fclean re
>>>>>>> pre-eval
