# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/19 11:51:57 by mkiflema          #+#    #+#              #
#    Updated: 2023/08/25 09:22:44 by hatesfam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# $(VERBOSE).SILENT:

NAME = push_swap

SRCS =  $(wildcard src/*.c utils/*.c)
OBJS = $(SRCS:.c=.o)
CC = gcc

CFLAGS = -Wall -Wextra -Werror -Iincludes
RM = rm -rf
LIBFT = ./includes/libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(ARCHIVE)
	@$(MAKE) -C ./includes/libft
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

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