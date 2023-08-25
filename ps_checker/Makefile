# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/20 00:06:57 by aandom            #+#    #+#              #
#    Updated: 2023/08/25 09:23:01 by hatesfam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ../includes/libft/libft.a

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

%.o : %.c 
	@$(CC) -c $(CFLAGS) $< -o $@

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT) 
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT)  -o $(NAME)
	@cp $(NAME) ../ 

$(LIBFT) :
	@cd ../includes/libft && make

clean :
	@rm -f $(OBJS)

fclean : clean 
	@rm -f $(NAME)
	@cd ../ && rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re