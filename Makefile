# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/19 11:51:57 by mkiflema          #+#    #+#              #
#    Updated: 2023/08/01 04:42:00 by aandom           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

SRCS =  $(wildcard src/*.c utils/*.c)

OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes -g

RM = rm -rf

all: ${NAME}
${NAME}: ${OBJS}
	#@${MAKE} -C ./libft
	@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}
	@echo "$(NAME): $(GREEN)'$(NAME)' was created!$(RESET)"

clean: 
	#@${MAKE} -C ./libft fclean
	@${RM} ${OBJS}
	@echo "$(NAME): $(RED)'object files' were deleted!$(RESET)"

fclean: clean
	@${RM} ${NAME}
	@echo "$(NAME): $(RED)'$(NAME)' was deleted!$(RESET)"

re: fclean all

.PHONY: all clean fclean re