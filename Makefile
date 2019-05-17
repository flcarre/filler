# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/11 17:54:03 by flcarre           #+#    #+#              #
#    Updated: 2019/04/29 18:48:04 by flcarre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = flcarre.filler

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
	   $(SRCDIR)ft_calcmap.c \
	   $(SRCDIR)ft_tracking.c \
	   $(SRCDIR)ft_isok.c \
	   $(SRCDIR)ft_dist.c \
	   $(SRCDIR)ft_resetmap.c \
	   $(SRCDIR)ft_free.c \
	   $(SRCDIR)ft_updatemap.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	@make re -C $(LIB)
	@$(CC) -I $(INCDIR) $(FLAGS) -o $@ $(OBJS) $(LIB)/libft.a
	@echo "make $(NAME)\033[0;32m ✓\033[0m"

all: $(NAME)

%.o: %.c $(INCDIR)/filler.h
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
