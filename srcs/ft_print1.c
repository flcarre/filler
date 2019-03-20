/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 07:15:19 by flcarre           #+#    #+#             */
/*   Updated: 2019/02/20 20:07:22 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print5(t_id *e, va_list args)
{
	int				w;
	int				r;
	int				t;

	t = 0;
	r = 0;
	w = va_arg(args, int);
	if ((e->fm & 4) != 4)
		((t = ft_wprocess0(e, w)) >= 0) ? (r += t) : 0;
	(t >= 0 && (t = ft_pprocess0(e, w)) >= 0) ? (r += t) : 0;
	if ((e->fm & 4) == 4)
		(t >= 0 && (t = ft_wprocess0(e, w)) >= 0) ? (r += t) : 0;
	return ((t < 0) ? -1 : r);
}

int	ft_print6(t_id *e, va_list args)
{
	char			*s;
	int				r;
	int				t;

	t = 0;
	r = 0;
	s = va_arg(args, char *);
	if ((e->fm & 4) != 4)
		((t = ft_wprocess1(e, s)) >= 0) ? (r += t) : 0;
	(t >= 0 && (t = ft_pprocess1(e, s)) >= 0) ? (r += t) : 0;
	if ((e->fm & 4) == 4)
		(t >= 0 && (t = ft_wprocess1(e, s)) >= 0) ? (r += t) : 0;
	return ((t < 0) ? -1 : r);
}

int	ft_print7(t_id *e, va_list args)
{
	wchar_t			*ws;
	int				r;
	int				t;

	t = 0;
	r = 0;
	ws = va_arg(args, wchar_t *);
	if ((e->fm & 4) != 4)
		((t = ft_wprocess2(e, ws)) >= 0) ? (r += t) : 0;
	(t >= 0 && (t = ft_pprocess2(e, ws)) >= 0) ? (r += t) : 0;
	if ((e->fm & 4) == 4)
		(t >= 0 && (t = ft_wprocess2(e, ws)) >= 0) ? (r += t) : 0;
	return ((t < 0) ? -1 : r);
}

int	ft_print8(t_id *e, va_list args)
{
	unsigned int	ui;
	int				r;
	int				t;

	t = 0;
	r = 0;
	ui = va_arg(args, unsigned int);
	ft_wcalc0(e, ui);
	if ((e->fm & 4) != 4)
		((t = ft_wprocess3(e, ui)) >= 0) ? (r += t) : 0;
	(t >= 0 && (t = ft_pprocess3(e, ui)) >= 0) ? (r += t) : 0;
	if ((e->fm & 4) == 4)
		(t >= 0 && (t = ft_wprocess3(e, ui)) >= 0) ? (r += t) : 0;
	return ((t < 0) ? -1 : r);
}

int	ft_print9(t_id *e, va_list args)
{
	unsigned short	us;
	int				r;
	int				t;

	t = 0;
	r = 0;
	us = (unsigned short)va_arg(args, unsigned int);
	ft_wcalc0(e, us);
	if ((e->fm & 4) != 4)
		((t = ft_wprocess3(e, us)) >= 0) ? (r += t) : 0;
	(t >= 0 && (t = ft_pprocess3(e, us)) >= 0) ? (r += t) : 0;
	if ((e->fm & 4) == 4)
		(t >= 0 && (t = ft_wprocess3(e, us)) >= 0) ? (r += t) : 0;
	return ((t < 0) ? -1 : r);
}
