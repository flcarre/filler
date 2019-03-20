# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 17:06:41 by lutsiara          #+#    #+#              #
#    Updated: 2019/03/07 07:18:07 by lutsiara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Werror -Wextra

SRCDIR = srcs/

INCDIR = includes/

LIBDIR = libft/

LIBSRCS = $(LIBDIR)$(SRCDIR)ft_atoi.c \
		  $(LIBDIR)$(SRCDIR)ft_bzero.c \
		  $(LIBDIR)$(SRCDIR)ft_digitlen.c \
		  $(LIBDIR)$(SRCDIR)ft_memalloc.c \
		  $(LIBDIR)$(SRCDIR)ft_memccpy.c \
		  $(LIBDIR)$(SRCDIR)ft_memchr.c \
		  $(LIBDIR)$(SRCDIR)ft_memcmp.c \
		  $(LIBDIR)$(SRCDIR)ft_memcpy.c \
		  $(LIBDIR)$(SRCDIR)ft_memdel.c \
		  $(LIBDIR)$(SRCDIR)ft_memmove.c \
		  $(LIBDIR)$(SRCDIR)ft_memset.c \
		  $(LIBDIR)$(SRCDIR)ft_iputchar.c \
		  $(LIBDIR)$(SRCDIR)ft_iputxchar.c \
		  $(LIBDIR)$(SRCDIR)ft_iputnbr_base.c \
		  $(LIBDIR)$(SRCDIR)ft_iputunbr_base.c \
		  $(LIBDIR)$(SRCDIR)ft_iputstr.c \
		  $(LIBDIR)$(SRCDIR)ft_iputnstr.c \
		  $(LIBDIR)$(SRCDIR)ft_strcmp.c \
		  $(LIBDIR)$(SRCDIR)ft_strlen.c \
		  $(LIBDIR)$(SRCDIR)ft_strncmp.c \
		  $(LIBDIR)$(SRCDIR)ft_strchr.c \
		  $(LIBDIR)$(SRCDIR)ft_strrchr.c \
		  $(LIBDIR)$(SRCDIR)ft_dmod.c \
		  $(LIBDIR)$(SRCDIR)ft_ldmod.c \
		  $(LIBDIR)$(SRCDIR)ft_dabs.c \
		  $(LIBDIR)$(SRCDIR)ft_ldabs.c \
		  $(LIBDIR)$(SRCDIR)ft_ldfrexp.c \
		  $(LIBDIR)$(SRCDIR)ft_dfrexp.c \
		  $(LIBDIR)$(SRCDIR)ft_ldexp.c \
		  $(LIBDIR)$(SRCDIR)ft_dexp.c \
		  $(LIBDIR)$(SRCDIR)ft_isnan.c \
		  $(LIBDIR)$(SRCDIR)ft_isinf.c \
		  $(LIBDIR)$(SRCDIR)ft_isdigit.c \
		  $(LIBDIR)$(SRCDIR)ft_isspace.c \
		  $(LIBDIR)$(SRCDIR)ft_dclassify.c \
		  $(LIBDIR)$(SRCDIR)ft_signbit.c \
		  $(LIBDIR)$(SRCDIR)ft_iputwchar.c \
		  $(LIBDIR)$(SRCDIR)ft_iputwstr.c \
		  $(LIBDIR)$(SRCDIR)ft_iputnwstr.c \
		  $(LIBDIR)$(SRCDIR)ft_atoui.c \
		  $(LIBDIR)$(SRCDIR)ft_wstrlen.c \
		  $(LIBDIR)$(SRCDIR)ft_wcharlen.c \
		  $(LIBDIR)$(SRCDIR)ft_ld_ldiglen.c \
		  $(LIBDIR)$(SRCDIR)ft_ull.c \
		  $(LIBDIR)$(SRCDIR)ft_udigitlen.c

LIBOBJS = $(LIBSRCS:.c=.o)

SRCS = $(SRCDIR)ft_printf.c \
	   $(SRCDIR)ft_parse.c \
	   $(SRCDIR)ft_converter.c \
	   $(SRCDIR)ft_dorounding.c \
	   $(SRCDIR)ft_idisnull.c \
	   $(SRCDIR)ft_isid.c \
	   $(SRCDIR)ft_isfm.c \
	   $(SRCDIR)ft_iputldnbr.c \
	   $(SRCDIR)ft_simuldnbr.c \
	   $(SRCDIR)ft_pprocess0.c \
	   $(SRCDIR)ft_pprocess1.c \
	   $(SRCDIR)ft_pprocess2.c \
	   $(SRCDIR)ft_pprocess3.c \
	   $(SRCDIR)ft_pprocess4.c \
	   $(SRCDIR)ft_print0.c \
	   $(SRCDIR)ft_print1.c \
	   $(SRCDIR)ft_print2.c \
	   $(SRCDIR)ft_print3.c \
	   $(SRCDIR)ft_printcolor.c \
	   $(SRCDIR)ft_wcalc.c \
	   $(SRCDIR)ft_wprocess0.c \
	   $(SRCDIR)ft_wprocess1.c \
	   $(SRCDIR)ft_wprocess2.c \
	   $(SRCDIR)ft_wprocess3.c \
	   $(SRCDIR)ft_wprocess4.c \

OBJS = $(SRCS:.c=.o)

$(NAME): $(LIBOBJS) $(OBJS)
	@ar rc $(NAME) $(OBJS) $(LIBOBJS)
	@ranlib $(NAME)
	@echo "make $(NAME)\033[0;32m ✓\033[0m"

all: $(NAME)

%.o: %.c
	@$(CC) -o $@ -c $< -I $(INCDIR) -I $(LIBDIR)$(INCDIR) $(FLAGS)

clean:
	@/bin/rm -rf $(OBJS) $(LIBOBJS)
	@echo "rm *.o\033[0;32m ✓\033[0m"

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo "rm $(NAME)\033[0;32m ✓\033[0m"

re: fclean all

.PHONY: all clean fclean re

.NOTPARALLEL: re
