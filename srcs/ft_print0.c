/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 07:15:19 by flcarre           #+#    #+#             */
/*   Updated: 2019/02/20 19:54:28 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print0(t_id *e, va_list args)
{
	int			i;
	int			r;
	int			t;

	t = 0;
	r = 0;
	i = va_arg(args, int);
	if ((e->fm & 4) != 4)
		((t = ft_wprocess0(e, i)) >= 0) ? (r += t) : 0;
	(t >= 0 && (t = ft_pprocess0(e, i)) >= 0) ? (r += t) : 0;
	if ((e->fm & 4) == 4)
		(t >= 0 && (t = ft_wprocess0(e, i)) >= 0) ? (r += t) : 0;
	return ((t < 0) ? -1 : r);
}

int	ft_print1(t_id *e, va_list args)
{
	short		s;
	int			r;
	int			t;

	t = 0;
	r = 0;
	s = (short)va_arg(args, int);
	if ((e->fm & 4) != 4)
		((t = ft_wprocess0(e, s)) >= 0) ? (r += t) : 0;
	(t >= 0 && (t = ft_pprocess0(e, s)) >= 0) ? (r += t) : 0;
	if ((e->fm & 4) == 4)
		(t >= 0 && (t = ft_wprocess0(e, s)) >= 0) ? (r += t) : 0;
	return ((t < 0) ? -1 : r);
}

int	ft_print2(t_id *e, va_list args)
{
	char		c;
	int			r;
	int			t;

	t = 0;
	r = 0;
	c = (char)va_arg(args, int);
	if ((e->fm & 4) != 4)
		((t = ft_wprocess0(e, c)) >= 0) ? (r += t) : 0;
	(t >= 0 && (t = ft_pprocess0(e, c)) >= 0) ? (r += t) : 0;
	if ((e->fm & 4) == 4)
		(t >= 0 && (t = ft_wprocess0(e, c)) >= 0) ? (r += t) : 0;
	return ((t < 0) ? -1 : r);
}

int	ft_print3(t_id *e, va_list args)
{
	long		l;
	int			r;
	int			t;

	t = 0;
	r = 0;
	l = va_arg(args, long);
	if ((e->fm & 4) != 4)
		((t = ft_wprocess0(e, l)) >= 0) ? (r += t) : 0;
	(t >= 0 && (t = ft_pprocess0(e, l)) >= 0) ? (r += t) : 0;
	if ((e->fm & 4) == 4)
		(t >= 0 && (t = ft_wprocess0(e, l)) >= 0) ? (r += t) : 0;
	return ((t < 0) ? -1 : r);
}

int	ft_print4(t_id *e, va_list args)
{
	long long	ll;
	int			r;
	int			t;

	t = 0;
	r = 0;
	ll = va_arg(args, long long);
	if ((e->fm & 4) != 4)
		((t = ft_wprocess0(e, ll)) >= 0) ? (r += t) : 0;
	(t >= 0 && (t = ft_pprocess0(e, ll)) >= 0) ? (r += t) : 0;
	if ((e->fm & 4) == 4)
		(t >= 0 && (t = ft_wprocess0(e, ll)) >= 0) ? (r += t) : 0;
	return ((t < 0) ? -1 : r);
}
