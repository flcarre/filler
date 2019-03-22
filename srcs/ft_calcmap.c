/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:03:58 by lutsiara          #+#    #+#             */
/*   Updated: 2019/03/22 05:42:09 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	ft_disttoadv4(t_data *data, unsigned int i, unsigned int j)
{
	unsigned int	x;
	unsigned int	y;
	int				tmp;
	int				mindist;

	mindist = -1;
	y = j + 1;
	while (y--)
	{
		x = i;
		x--;
		while (data->m.p[++x])
			if (data->m.p[x][y] == data->ad)
			{
				tmp = (x - i >= j - y) ? x - i : j - y;
				mindist = (tmp <= mindist || mindist < 0) ? tmp : mindist;
			}
	}
	return (mindist);
}

static int	ft_disttoadv3(t_data *data, unsigned int i, unsigned int j)
{
	unsigned int	x;
	unsigned int	y;
	int				tmp;
	int				mindist;

	mindist = -1;
	y = j;
	while (data->m.p[i][y])
	{
		x = i + 1;
		while (x--)
			if (data->m.p[x][y] == data->ad)
			{
				tmp = (i - x >= y - j) ? i - x : y - j;
				mindist = (tmp <= mindist || mindist < 0) ? tmp : mindist;
			}
		y++;
	}
	tmp = ft_disttoadv4(data, i, j);
	mindist = ((tmp <= mindist || mindist < 0) && tmp >= 0) ? tmp : mindist;
	return (mindist);
}

static int	ft_disttoadv2(t_data *data, unsigned int i, unsigned int j)
{
	unsigned int	x;
	unsigned int	y;
	int				tmp;
	int				mindist;

	mindist = -1;
	y = j + 1;
	while (y--)
	{
		x = i + 1;
		while (x--)
			if (data->m.p[x][y] == data->ad)
			{
				tmp = (i - x >= j - y) ? i - x : j - y;
				mindist = (tmp <= mindist || mindist < 0) ? tmp : mindist;
			}
	}
	tmp = ft_disttoadv3(data, i, j);
	mindist = ((tmp <= mindist || mindist < 0) && tmp >= 0) ? tmp : mindist;
	return (mindist);
}

static int	ft_disttoadv(t_data *data, unsigned int i, unsigned int j)
{
	unsigned int	x;
	unsigned int	y;
	int				tmp;
	int				mindist;

	if (data->m.p[i][j] == data->me || data->m.p[i][j] == data->ad)
		return (0);
	mindist = -1;
	y = j;
	while (data->m.p[i][y])
	{
		x = i;
		x--;
		while (data->m.p[++x])
			if (data->m.p[x][y] == data->ad)
			{
				tmp = (x - i >= y - j) ? x - i : y - j;
				mindist = (tmp <= mindist || mindist < 0) ? tmp : mindist;
			}
		y++;
	}
	tmp = ft_disttoadv2(data, i, j);
	mindist = ((tmp <= mindist || mindist < 0) && tmp >= 0) ? tmp : mindist;
	return (mindist);
}

int			ft_calcmap(t_data *data)
{
	unsigned int	i;
	unsigned int	j;
	int				maxdist;
	int				tmp;

	i = 0;
	maxdist = 0;
	while (data->m.p[i])
	{
		j = 0;
		while (data->m.p[i][j])
		{
			tmp = ft_disttoadv(data, i, j);
			maxdist = (tmp > maxdist) ? tmp : maxdist;
			data->i.p[i][j] = tmp;
			j++;
		}
		i++;
	}
	return (maxdist);
}
