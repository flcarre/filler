/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pprocess1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:20:22 by flcarre           #+#    #+#             */
/*   Updated: 2019/02/20 16:36:48 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_pprocess1(t_id *e, char *s)
{
	long	r[2];

	r[0] = 0;
	if (e->p[1])
	{
		if (!s && (r[1] = ft_iputnstr("(null)", e->p[0])) >= 0)
			r[0] += r[1];
		else if (s && (r[1] = ft_iputnstr(s, e->p[0])) >= 0)
			r[0] += r[1];
		r[0] = (r[1] < 0) ? r[1] : r[0];
		return ((int)r[0]);
	}
	if (!s && (r[1] = ft_iputstr("(null)")) >= 0)
		r[0] += r[1];
	else if (s && (r[1] = ft_iputstr(s)) >= 0)
		r[0] += r[1];
	r[0] = (r[1] < 0) ? r[1] : r[0];
	return ((int)r[0]);
}
