/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tracking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 19:34:46 by flcarre           #+#    #+#             */
/*   Updated: 2019/04/29 18:49:55 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static unsigned int	ft_calcx(t_tab *p)
{
	unsigned int	x;
	unsigned int	i;
	unsigned int	j;
	char			u;

	u = 1;
	x = 0;
	i = 0;
	while (i < p->y)
	{
		j = 0;
		while (j < p->x)
		{
			if (p->p[i][j] == '*' && (x > j || u))
			{
				u = 0;
				x = j;
			}
			j++;
		}
		i++;
	}
	return (x);
}

static unsigned int	ft_calcy(t_tab *p)
{
	unsigned int	y;
	unsigned int	i;
	unsigned int	j;
	char			u;

	u = 1;
	y = 0;
	i = 0;
	while (i < p->y)
	{
		j = 0;
		while (j < p->x)
		{
			if (p->p[i][j] == '*' && (y > i || u))
			{
				u = 0;
				y = i;
			}
			j++;
		}
		i++;
	}
	return (y);
}

static void			ft_sizemodif(t_tab *piece)
{
	t_pos			v;

	v.y = 0;
	v.x = 0;
	v.i = piece->y;
	while (v.i--)
	{
		v.j = piece->x;
		while (v.j--)
		{
			if (piece->p[v.i][v.j] == '*' && v.y < v.i + 1)
				v.y = v.i + 1;
			if (piece->p[v.i][v.j] == '*' && v.x < v.j + 1)
				v.x = v.j + 1;
		}
	}
	piece->y = v.y;
	piece->x = v.x;
}

static void			ft_posinit(t_pos *p, t_tab *piece)
{
	p->d = -1;
	p->f = 0;
	p->x = 0;
	p->y = 0;
	p->i = 0;
	p->j = 0;
	p->sx = ft_calcx(piece);
	p->sy = ft_calcy(piece);
	ft_sizemodif(piece);
}

int					ft_tracking(t_data *data)
{
	t_pos			p;

	ft_posinit(&p, &data->p);
	while (p.i + data->p.y - 1 < data->m.y)
	{
		while (p.j + data->p.x - 1 < data->m.x)
		{
			if (ft_isok(data, &p))
				if (p.d == -1 || ft_dist(data, &p) < p.d)
				{
					p.f = 1;
					p.x = p.i;
					p.y = p.j;
					p.d = ft_dist(data, &p);
				}
			p.j++;
		}
		p.j = 0;
		p.i++;
	}
	data->px = (int)(p.x - p.sy);
	data->py = (int)(p.y - p.sx);
	return (!p.f);
}
