/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wprocess2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 21:15:30 by lutsiara          #+#    #+#             */
/*   Updated: 2019/03/07 03:54:18 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_w(t_id *e)
{
	long			r[2];

	r[0] = 0;
	if (e->p[1] && e->p[0] < (unsigned int)ft_strlen("(null)"))
		e->w -= (e->w >= e->p[0]) ? e->p[0] : e->w;
	else
		e->w -= (e->w >= ft_strlen("(null)")) ? \
		(unsigned int)ft_strlen("(null)") : e->w;
	if ((e->fm & 8) == 8 && (e->fm & 4) != 4)
		((r[1] = ft_iputxchar('0', e->w)) >= 0) ? (r[0] += r[1]) : 0;
	else
		((r[1] = ft_iputxchar(' ', e->w)) >= 0) ? (r[0] += r[1]) : 0;
	return ((int)((r[1] < 0) ? -1 : r[0]));
}

static void	ft_wpcount(t_id *e, wchar_t *ws)
{
	unsigned long	t;
	unsigned long	p;

	p = e->p[0];
	while (*ws)
	{
		t = ft_wcharlen(*(ws++));
		if (p >= t)
		{
			e->w -= (e->w >= t) ? t : e->w;
			p -= t;
		}
		else
			return ;
	}
}

static void	ft_wcount(t_id *e, wchar_t *ws)
{
	unsigned long	t;

	while (e->w && *ws)
	{
		t = ft_wcharlen(*(ws++));
		if (e->w >= t)
			e->w -= t;
		else
			e->w = 0;
	}
}

int			ft_wprocess2(t_id *e, wchar_t *ws)
{
	long			r[2];

	r[0] = 0;
	if (!ws)
		return (ft_w(e));
	if (e->p[1] && (e->p[0] <= (unsigned int)ft_wstrlen(ws) || \
	e->p[0] - ft_wcharlen(*(ws + ft_wstrlen(ws) - 1)) <= ft_wstrlen(ws)))
		ft_wpcount(e, ws);
	else
		ft_wcount(e, ws);
	if ((e->fm & 8) == 8 && (e->fm & 4) != 4)
		((r[1] = ft_iputxchar('0', e->w)) >= 0) ? (r[0] += r[1]) : 0;
	else
		((r[1] = ft_iputxchar(' ', e->w)) >= 0) ? (r[0] += r[1]) : 0;
	return ((int)((r[1] < 0) ? -1 : r[0]));
}
