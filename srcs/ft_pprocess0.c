/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pprocess0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 16:22:11 by lutsiara          #+#    #+#             */
/*   Updated: 2019/02/27 17:53:43 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_c(t_id *e, long long x)
{
	long	r[2];

	r[0] = 0;
	r[1] = 0;
	if ((e->fm & 8) == 8 && (e->fm & 4) != 4)
	{
		((r[1] = ft_iputxchar('0', e->w)) >= 0) ? (r[0] += r[1]) : 0;
		e->w = 0;
	}
	if (r[1] >= 0 && e->lm[0] == 'l' && (r[1] = ft_iputwchar(x)) >= 0)
		r[0] += r[1];
	else if (r[1] >= 0 && (r[1] = ft_iputchar(x)) >= 0)
		r[0] += r[1];
	r[0] = (r[1] < 0) ? r[1] : r[0];
	return ((int)r[0]);
}

static int	ft_iputfm(t_id *e, long long x)
{
	long	r[2];

	r[0] = 0;
	r[1] = 0;
	if (x < 0 && (r[1] = ft_iputchar('-')) >= 0)
		r[0] += r[1];
	else if (r[1] >= 0 && (e->fm & 2) == 2 && (e->fm & 1) != 1 && \
	(r[1] = ft_iputchar(' ')) >= 0)
		r[0] += r[1];
	else if (r[1] >= 0 && (e->fm & 1) == 1 && (r[1] = ft_iputchar('+')) >= 0)
		r[0] += r[1];
	if (r[1] >= 0 && (e->fm & 8) == 8 && (e->fm & 4) != 4 && !e->p[1])
	{
		((r[1] = ft_iputxchar('0', e->w)) >= 0) ? (r[0] += r[1]) : 0;
		e->w = 0;
	}
	r[0] = (r[1] < 0) ? r[1] : r[0];
	return ((int)r[0]);
}

int			ft_pprocess0(t_id *e, long long x)
{
	long	r[2];

	r[0] = 0;
	if (e->id[0] == 'c')
		return (ft_c(e, x));
	((r[1] = ft_iputfm(e, x)) >= 0) ? (r[0] += r[1]) : 0;
	if (r[1] >= 0 && e->p[1] && e->p[0] > ft_digitlen(x, 10))
		((r[1] = ft_iputxchar('0', e->p[0] - ft_digitlen(x, 10))) >= 0) \
		? (r[0] += r[1]) : 0;
	if (r[1] >= 0 && !(e->p[1] && !e->p[0] && x == 0) && \
	(r[1] = ft_iputunbr_base(((x < 0) ? -x : x), "0123456789")) >= 0)
		r[0] += r[1];
	r[0] = (r[1] < 0) ? r[1] : r[0];
	return ((int)r[0]);
}
