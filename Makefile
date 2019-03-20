# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/11 17:54:03 by lutsiara          #+#    #+#              #
#    Updated: 2019/03/20 05:08:19 by lutsiara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lutsiara.filler

CC = gcc

FLAGS = -Wall -Werror -Wextra

SRCDIR = ./srcs/

INCDIR = ./includes/

LIB = ./libft

SRCS = $(SRCDIR)main.c \
	   $(SRCDIR)ft_init.c \
	   $(SRCDIR)ft_whoami.c \
	   $(SRCDIR)ft_getmap.c \
	   $(SRCDIR)ft_alloccalc.c \
	   $(SRCDIR)ft_getpiece.c \
	   $(SRCDIR)ft_fight.c \
	   $(SRCDIR)ft_free.c \
	   $(SRCDIR)ft_updatemap.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	@make -C $(LIB)
	@$(CC) -I $(INCDIR) $(FLAGS) -o $@ $(OBJS) $(LIB)/libft.a
	@echo "make $(NAME)\033[0;32m ✓\033[0m"

all: $(NAME)

%.o: %.c
	@$(CC) -o $@ -c $< -I $(INCDIR) $(FLAGS)

clean:
	@/bin/rm -rf $(OBJS)
	@make -C $(LIB) clean
	@echo "rm *.o\033[0;32m ✓\033[0m"

fclean: clean
	@/bin/rm -rf $(NAME)
	@make -C $(LIB) fclean
	@echo "rm $(NAME)\033[0;32m ✓\033[0m"

re: fclean all

.PHONY: all clean fclean re

.NOTPARALLEL: re
