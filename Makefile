# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/19 11:51:57 by mkiflema          #+#    #+#              #
#    Updated: 2023/08/04 13:24:19 by aandom           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS =  $(wildcard src/*.c utils/*.c)
OBJS = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes  -O2 -g
ARCHIVE = push_swap.a
MAKE_ARC = ar -rcs
RM = rm -rf

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: ${NAME}

${NAME}: ${OBJS} $(ARCHIVE)
	#@${MAKE} -C ./libft
	@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}
	@echo "$(NAME): $(GREEN)'$(NAME)' was created!$(RESET)"

$(ARCHIVE) : $(OBJS)
	$(MAKE_ARC) $(ARCHIVE) $^
	@echo "$(NAME): $(GREEN)'$(ARCHIVE)' was created!$(RESET)"

bonus : 
	cd ./ps_checker && make
		
clean: 
	#@${MAKE} -C ./libft fclean
	@${RM} ${OBJS} $(ARCHIVE)
	@echo "$(NAME): $(RED)'object files' were deleted!$(RESET)"
	@echo "$(NAME): $(RED)'$(ARCHIVE)' was deleted!$(RESET)"

fclean: clean
	@${RM} ${NAME}
	@echo "$(NAME): $(RED)'$(NAME)' was deleted!$(RESET)"
	cd ./ps_checker && make fclean

re: fclean all

.PHONY: all clean fclean re