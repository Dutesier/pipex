# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dareias- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/22 11:02:11 by dareias-          #+#    #+#              #
#    Updated: 2021/09/29 11:19:26 by dareias-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc
CFLAGS = -Wall -Wextra -Werror

IDIR = -I./includes

SRCS = main.c \
	   srcs/ft_findpath.c \
	   srcs/ft_append.c \
	   srcs/ft_split.c \
	   srcs/ft_strcmp.c \
	   srcs/ft_getfd.c \
	   srcs/ft_processes.c \

OBJS = $(SRCS:.c=.o) 

$(NAME): $(OBJS)
	$(CC) $^ $(IDIR) $(CFLAGS) -o $@

all: $(NAME)

clean:
	rm -rf $(OBJS) *.o

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: clean fclean re
