/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isok.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 19:34:54 by lutsiara          #+#    #+#             */
/*   Updated: 2019/03/25 20:06:03 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_isok(t_data *data, t_pos *p)
{
	char	c;
	t_pos	t;

	c = 0;
	t.i = 0;
	while (t.i < data->p.y)
	{
		t.j = 0;
		while (t.j < data->p.x)
		{
			if (data->m.p[p->i + t.i][p->j + t.j] == data->me && \
			data->p.p[t.i][t.j] == '*')
				c++;
			if ((data->m.p[p->i + t.i][p->j + t.j] == data->ad && \
			data->p.p[t.i][t.j] == '*') || c > 1)
				return (0);
			t.j++;
		}
		t.i++;
	}
	if (!c)
		return (0);
	return (1);
}