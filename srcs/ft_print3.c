/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 07:15:19 by flcarre           #+#    #+#             */
/*   Updated: 2019/02/27 17:17:42 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print15(t_id *e, va_list args)
{
	void			*p;
	int				r;
	int				t;

	t = 0;
	r = 0;
	p = va_arg(args, void *);
	ft_wcalc0(e, (unsigned long long)p);
	if ((e->fm & 4) != 4)
		((t = ft_wprocess3(e, (unsigned long long)p)) >= 0) ? (r += t) : 0;
	(t >= 0 && (t = ft_pprocess3(e, (unsigned long long)p)) >= 0) ? \
	(r += t) : 0;
	if ((e->fm & 4) == 4)
		(t >= 0 && (t = ft_wprocess3(e, (unsigned long long)p)) >= 0) ? \
		(r += t) : 0;
	return ((t < 0) ? -1 : r);
}

int	ft_print16(t_id *e, va_list args)
{
	(void)args;
	return (ft_printcolor(e));
}

int	ft_print17(t_id *e, va_list args)
{
	long	r[2];

	(void)args;
	r[0] = 0;
	e->w -= (e->w >= 1) ? 1 : e->w;
	if ((e->fm & 8) == 8 && (e->fm & 4) != 4)
		((r[1] = ft_iputxchar('0', e->w)) >= 0) ? (r[0] += r[1]) : 0;
	else if ((e->fm & 4) != 4)
		((r[1] = ft_iputxchar(' ', e->w)) >= 0) ? (r[0] += r[1]) : 0;
	(r[1] >= 0 && (r[1] = ft_iputchar('%')) >= 0) ? (r[0] += r[1]) : 0;
	if ((e->fm & 4) == 4)
		((r[1] = ft_iputxchar(' ', e->w)) >= 0) ? (r[0] += r[1]) : 0;
	return ((int)(r[1] < 0) ? -1 : r[0]);
}
