/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wprocess0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 21:15:30 by lutsiara          #+#    #+#             */
/*   Updated: 2019/03/06 21:31:44 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_wprocess0(t_id *e, long long x)
{
	long	r[2];

	r[0] = 0;
	e->w -= (e->id[0] != 'c' && x == 0 && e->w > 0 && !e->p[1]) ? 1 : 0;
	if (e->id[0] == 'c')
	{
		if (e->lm[0] == 'l')
			e->w -= (e->w >= ft_wcharlen(x)) ? ft_wcharlen(x) : e->w;
		else
			e->w -= (e->w >= 1) ? 1 : e->w;
		if (((e->fm & 8) != 8 || ((e->fm & 8) == 8 && (e->fm & 4) == 4)) && \
		(r[1] = ft_iputxchar(' ', e->w)) >= 0)
			r[0] += r[1];
		return ((int)((r[1] < 0) ? -1 : r[0]));
	}
	if (e->p[1] && e->p[0] >= ft_digitlen(x, 10))
		e->w = (e->w >= e->p[0]) ? e->w - e->p[0] : 0;
	else if (x != 0)
		e->w -= (e->w >= ft_digitlen(x, 10)) ? ft_digitlen(x, 10) : e->w;
	if (x < 0 || (e->fm & 1) == 1 || (e->fm & 2) == 2)
		e->w -= (e->w >= 1) ? 1 : e->w;
	if ((e->fm & 8) != 8 || ((e->fm & 8) == 8 && (e->fm & 4) == 4) || e->p[1])
		((r[1] = ft_iputxchar(' ', e->w)) >= 0) ? (r[0] += r[1]) : 0;
	return ((int)((r[1] < 0) ? -1 : r[0]));
}
