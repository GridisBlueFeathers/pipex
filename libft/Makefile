# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svereten <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 14:07:03 by svereten          #+#    #+#              #
#    Updated: 2024/05/30 13:31:17 by svereten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = src

OBJS_DIR = obj

OBJS_DIRS = $(sort $(dir $(OBJS)))

SRCS_PROJ = libft/ft_isalnum \
			libft/ft_isalpha \
			libft/ft_isascii \
			libft/ft_isdigit \
			libft/ft_isprint \
			libft/ft_memset \
			libft/ft_strlen \
			libft/ft_bzero \
			libft/ft_memcpy \
			libft/ft_memmove \
			libft/ft_memchr \
			libft/ft_memcmp \
			libft/ft_toupper \
			libft/ft_tolower \
			libft/ft_strchr \
			libft/ft_strrchr \
			libft/ft_strncmp \
			libft/ft_strlcpy \
			libft/ft_strlcat \
			libft/ft_strnstr \
			libft/ft_atoi \
			libft/ft_calloc \
			libft/ft_strdup \
			libft/ft_substr \
			libft/ft_strjoin \
			libft/ft_strtrim \
			libft/ft_split \
			libft/ft_itoa \
			libft/ft_strmapi \
			libft/ft_striteri \
			libft/ft_putchar_fd \
			libft/ft_putstr_fd \
			libft/ft_putendl_fd \
			libft/ft_putnbr_fd \
			libft/ft_lstnew \
			libft/ft_lstadd_front \
			libft/ft_lstadd_back \
			libft/ft_lstsize \
			libft/ft_lstlast \
			libft/ft_lstdelone \
			libft/ft_lstclear \
			libft/ft_lstiter \
			libft/ft_lstmap \
			libft/ft_free_n_null \
			libft/ft_validate_atoi \
			libft/ft_intlen \
			get-next-line/get_next_line \
			ft-printf/ft_print_char \
			ft-printf/ft_print_string \
			ft-printf/ft_print_int \
			ft-printf/ft_print_uint \
			ft-printf/ft_print_uhex \
			ft-printf/ft_print_pointer_addr \
			ft-printf/ft_printf \

SRCS = ${SRCS_PROJ:%=${SRCS_DIR}/%.c}

OBJS = ${SRCS_PROJ:%=${OBJS_DIR}/%.o}

INCLUDES = -I./include

AR = ar -rcs

RM = rm -f

all: ${NAME}

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}

bonus: ${BONUS_OBJS} ${OBJS}
	${AR} ${NAME} $^

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c | ${OBJS_DIRS}
	${CC} ${CFLAGS} -c $< ${INCLUDES} -o $@ 

${OBJS_DIRS}:
	mkdir -p $@

clean:
	${RM} ${OBJS} ${BONUS_OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re
