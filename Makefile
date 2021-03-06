# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dareias- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/22 11:02:11 by dareias-          #+#    #+#              #
#    Updated: 2021/09/29 19:16:14 by dareias-         ###   ########.fr        #
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
	   srcs/ft_putstr_fd.c \
	   srcs/ft_error.c \
	   srcs/ft_cleaner.c \

OBJS = $(SRCS:.c=.o) 

$(NAME): $(OBJS)
	$(CC) $^ $(IDIR) $(CFLAGS) -o $@

all: $(NAME)

clean:
	rm -rf $(OBJS) *.o

fclean: clean
	rm $(NAME)

re: fclean all

sanitize: $(OBJS)
	$(CC) $(OBJS) $(IDIR) $(CFLAGS) -fsanitize=address -o pipex

.PHONY: clean fclean re
