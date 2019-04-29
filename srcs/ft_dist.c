/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 20:14:21 by flcarre           #+#    #+#             */
/*   Updated: 2019/04/29 18:49:04 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_dist(t_data *data, t_pos *p)
{
	int		distmin;
	t_pos	t;

	distmin = -1;
	t.i = 0;
	while (t.i + p->sy < data->p.y)
	{
		t.j = 0;
		while (t.j + p->sx < data->p.x)
		{
			if (data->p.p[t.i + p->sy][t.j + p->sx] == '*' && \
			data->m.p[p->i + t.i][p->j + t.j] != data->me)
			{
				if (distmin == -1 || \
				distmin > data->i.p[p->i + t.i][p->j + t.j])
					distmin = data->i.p[p->i + t.i][p->j + t.j];
			}
			t.j++;
		}
		t.i++;
	}
	return (distmin);
}
