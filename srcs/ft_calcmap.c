/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:03:58 by lutsiara          #+#    #+#             */
/*   Updated: 2019/03/21 00:11:58 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	ft_calcangles(t_data *data)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (data->m.p[i])
	{
		j = 0;
		while (data->m.p[i][j]])
			ft_set(data, i, j++);
		i++;
	}
	return (ft_inttabmax(&data->i.p, data->i.x, data->i.y));
}

int			ft_calcmap(t_data *data)
{
	unsigned int	i;
	int				r;

	r = ft_calcangles(data);
	i = 0;
	while (data->m.p[i])
		ft_translatex(data, i++);
	i = 0;
	while (data->m.p[0][i])
		ft_translatey(data, i++);
	return (r);
}
