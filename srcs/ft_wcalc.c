/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcalc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:05:35 by flcarre           #+#    #+#             */
/*   Updated: 2019/03/07 08:11:11 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_0(t_id *e, unsigned long long x)
{
	if (e->id[0] == 'o')
	{
		if (e->p[1] && e->p[0] >= ft_udigitlen(x, 8))
			e->w = (e->w >= e->p[0]) ? e->w - e->p[0] : 0;
		else if (x != 0)
			e->w -= (e->w >= ft_udigitlen(x, 8)) ? ft_udigitlen(x, 8) : e->w;
	}
	else if (e->id[0] == 'x' || e->id[0] == 'X' || e->id[0] == 'p')
	{
		if (e->p[1] && e->p[0] >= ft_udigitlen(x, 16))
			e->w = (e->w >= e->p[0]) ? e->w - e->p[0] : 0;
		else if (x != 0 || e->id[0] == 'p')
			e->w -= (e->w >= ft_udigitlen(x, 16)) ? ft_udigitlen(x, 16) : e->w;
	}
	else
	{
		if (e->p[1] && e->p[0] >= ft_udigitlen(x, 10))
			e->w = (e->w >= e->p[0]) ? e->w - e->p[0] : 0;
		else if (x != 0)
			e->w -= (e->w >= ft_udigitlen(x, 10)) ? ft_udigitlen(x, 10) : e->w;
	}
}

void		ft_wcalc0(t_id *e, unsigned long long x)
{
	if (e->id[0] == 'o' && (e->fm & 16) == 16 && e->p[1] && x != 0)
		e->p[0] -= (e->p[0] >= 1) ? 1 : e->p[0];
	ft_0(e, x);
	if (e->id[0] == 'o' && (e->fm & 16) == 16 && x != 0)
		e->w -= (e->w >= 1) ? 1 : e->w;
	if ((e->id[0] == 'x' || e->id[0] == 'X') && (e->fm & 16) == 16 && x != 0)
		e->w -= (e->w >= 2) ? 2 : e->w;
	if (e->id[0] == 'p')
		e->w -= (e->w >= 2) ? 2 : e->w;
}

void		ft_wcalc1(t_id *e, long double x)
{
	long	r;

	r = ft_simuldnbr(x, e);
	if (ft_isnan(x) || ft_isinf(x))
		e->w -= (e->w >= (unsigned int)r) ? (unsigned int)r : e->w;
	else
		e->w -= (e->w >= (unsigned int)r - 1) ? (unsigned int)r - 1 : e->w;
	if (!e->p[0] && (e->fm & 16) == 16 && !ft_isnan(x) && !ft_isinf(x))
		e->w -= (e->w >= 1) ? 1 : e->w;
	else if (e->p[0] && !ft_isnan(x) && !ft_isinf(x))
		e->w -= (e->w >= 1) ? 1 : e->w;
	if (!ft_isnan(x) && (ft_signbit((void *)0, &x) || \
	(e->fm & 1) == 1 || (e->fm & 2) == 2))
		e->w -= (e->w >= 1) ? 1 : e->w;
}
