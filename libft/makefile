# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkiflema <mkiflema@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/20 16:55:23 by kvinarao          #+#    #+#              #
#    Updated: 2023/07/19 11:49:27 by mkiflema         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

AR			= ar
INCLUDES	= libft.h

RM			= rm -f

SRCS		= ft_atoi.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_isdigit.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_split.c \
				ft_strlen.c \


OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o : %.c
				$(CC) $(CFLAGS) -c $< -o $@

clean : 
				$(RM) $(OBJS)

fclean : clean 
				$(RM) $(NAME)

$(NAME) : $(OBJS)
				$(AR) $(ARFLAGS) $@ $^

re :			fclean	all

.PHONY :all clean fclean re