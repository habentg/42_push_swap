# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/19 11:51:57 by mkiflema          #+#    #+#              #
#    Updated: 2023/08/20 00:12:11 by aandom           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# $(VERBOSE).SILENT:

NAME = push_swap

SRCS =  $(wildcard src/*.c utils/*.c)
OBJS = $(SRCS:.c=.o)
CC = gcc

CFLAGS = -Wall -Wextra -Werror -Iincludes  -fsanitize=address -g3
ARCHIVE = push_swap.a
MAKE_ARC = ar -rcs
RM = rm -rf
LIBFT = ./includes/libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(ARCHIVE)
	@$(MAKE) -C ./includes/libft
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(ARCHIVE) : $(OBJS)
	@$(MAKE_ARC) $(ARCHIVE) $^

bonus : 
	@cd ./ps_checker && make
		
clean: 
	@$(MAKE) -C ./includes/libft fclean
	@$(RM) $(OBJS) $(ARCHIVE)

fclean: clean
	@$(RM) $(NAME)
	@cd ./ps_checker && make fclean

re: fclean all

.PHONY: all clean fclean re