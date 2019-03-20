/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wprocess1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 21:15:30 by lutsiara          #+#    #+#             */
/*   Updated: 2019/02/21 17:29:29 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_w(t_id *e)
{
	long	r[2];

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

int			ft_wprocess1(t_id *e, char *s)
{
	long	r[2];

	r[0] = 0;
	if (!s)
		return (ft_w(e));
	if (e->p[1] && e->p[0] < (unsigned int)ft_strlen(s))
		e->w = (e->w >= e->p[0]) ? e->w - e->p[0] : 0;
	else
		e->w -= (e->w >= ft_strlen(s)) ? ft_strlen(s) : e->w;
	if ((e->fm & 8) == 8 && (e->fm & 4) != 4)
		((r[1] = ft_iputxchar('0', e->w)) >= 0) ? (r[0] += r[1]) : 0;
	else
		((r[1] = ft_iputxchar(' ', e->w)) >= 0) ? (r[0] += r[1]) : 0;
	return ((int)r[0]);
}
