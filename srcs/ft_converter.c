/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 16:50:09 by flcarre           #+#    #+#             */
/*   Updated: 2019/03/07 04:53:10 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_glo_print.h"

static void	conv_maj(t_id *e)
{
	if (e->id[0] == 'D' || e->id[0] == 'U' || e->id[0] == 'O' \
	|| e->id[0] == 'C' || e->id[0] == 'S' || e->id[0] == 'F')
	{
		e->lm[0] = 'l';
		e->lm[1] = 0;
		if (e->id[0] == 'F')
			e->p[1] = 2;
		e->id[0] += 32;
	}
}

static int	ft_printarg(t_id *e, va_list args, int *r)
{
	int		i;
	int		t;

	t = 1;
	i = 60 + 1;
	conv_maj(e);
	while (t && --i)
		if (!ft_strcmp(e->id, g_print[i - 1].id) && \
		!ft_strcmp(e->lm, g_print[i - 1].lm))
			t = 0;
	if (i && (t = g_print[i - 1].f(e, args)) >= 0)
		*r += t;
	else if (i && t < 0)
		*r = t;
	else
		*r = -1;
	return ((!i) ? 1 : 0);
}

int			ft_converter(char **fmt, va_list args, int *r)
{
	t_id	e;

	(*fmt)++;
	ft_parse(&e, fmt, args);
	if (ft_idisnull(&e))
		return (1);
	if (e.id[0] && ft_printarg(&e, args, r))
		return (1);
	return (0);
}
