/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glo_print.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 02:05:05 by flcarre           #+#    #+#             */
/*   Updated: 2019/02/27 17:37:43 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GLO_PRINT_H
# define FT_GLO_PRINT_H

# include "ft_printf.h"

typedef struct				s_print
{
	int						(*f)(t_id *, va_list);
	char					lm[3];
	char					id[10];
}							t_print;

t_print						g_print[] = {
	{&ft_print0, "", "i"},
	{&ft_print1, "h", "i"},
	{&ft_print2, "hh", "i"},
	{&ft_print3, "l", "i"},
	{&ft_print4, "ll", "i"},
	{&ft_print0, "", "d"},
	{&ft_print1, "h", "d"},
	{&ft_print2, "hh", "d"},
	{&ft_print3, "l", "d"},
	{&ft_print4, "ll", "d"},
	{&ft_print2, "", "c"},
	{&ft_print5, "l", "c"},
	{&ft_print6, "", "s"},
	{&ft_print7, "l", "s"},
	{&ft_print8, "", "o"},
	{&ft_print9, "h", "o"},
	{&ft_print10, "hh", "o"},
	{&ft_print11, "l", "o"},
	{&ft_print12, "ll", "o"},
	{&ft_print8, "", "u"},
	{&ft_print9, "h", "u"},
	{&ft_print10, "hh", "u"},
	{&ft_print11, "l", "u"},
	{&ft_print12, "ll", "u"},
	{&ft_print8, "", "x"},
	{&ft_print9, "h", "x"},
	{&ft_print10, "hh", "x"},
	{&ft_print11, "l", "x"},
	{&ft_print12, "ll", "x"},
	{&ft_print8, "", "X"},
	{&ft_print9, "h", "X"},
	{&ft_print10, "hh", "X"},
	{&ft_print11, "l", "X"},
	{&ft_print12, "ll", "X"},
	{&ft_print13, "", "f"},
	{&ft_print13, "l", "f"},
	{&ft_print14, "L", "f"},
	{&ft_print15, "", "p"},
	{&ft_print15, "l", "p"},
	{&ft_print15, "ll", "p"},
	{&ft_print16, "", "{}"},
	{&ft_print16, "", "{BLACK}"},
	{&ft_print16, "", "{RED}"},
	{&ft_print16, "", "{GREEN}"},
	{&ft_print16, "", "{YELLOW}"},
	{&ft_print16, "", "{BLUE}"},
	{&ft_print16, "", "{PURPLE}"},
	{&ft_print16, "", "{CYAN}"},
	{&ft_print16, "", "{WHITE}"},
	{&ft_print16, "", "{GREY}"},
	{&ft_print16, "", "{ORANGE}"},
	{&ft_print16, "", "{HBLACK}"},
	{&ft_print16, "", "{HRED}"},
	{&ft_print16, "", "{HGREEN}"},
	{&ft_print16, "", "{HYELLOW}"},
	{&ft_print16, "", "{HBLUE}"},
	{&ft_print16, "", "{HPURPLE}"},
	{&ft_print16, "", "{HCYAN}"},
	{&ft_print16, "", "{HWHITE}"},
	{&ft_print17, "", "%"}
};

#endif
