/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pprocess2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:20:22 by flcarre           #+#    #+#             */
/*   Updated: 2019/02/20 16:22:42 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_pprocess2(t_id *e, wchar_t *ws)
{
	long	r[2];

	r[0] = 0;
	if (e->p[1])
	{
		if (!ws && (r[1] = ft_iputnstr("(null)", e->p[0])) >= 0)
			r[0] += r[1];
		else if (ws && (r[1] = ft_iputnwstr(ws, e->p[0])) >= 0)
			r[0] += r[1];
		r[0] = (r[1] < 0) ? r[1] : r[0];
		return ((int)r[0]);
	}
	if (!ws && (r[1] = ft_iputstr("(null)")) >= 0)
		r[0] += r[1];
	else if (ws && (r[1] = ft_iputwstr(ws)) >= 0)
		r[0] += r[1];
	r[0] = (r[1] < 0) ? r[1] : r[0];
	return ((int)r[0]);
}
