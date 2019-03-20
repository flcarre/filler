/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloccalc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 04:53:25 by lutsiara          #+#    #+#             */
/*   Updated: 2019/03/20 04:59:26 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_alloccalc(t_data *data)
{
	unsigned int	x;
	unsigned int	y;

	data->i.x = data->m.x;
	data->i.y = data->m.y;
	x = data->m.x;
	y = data->m.y;
	if (!(data->i.p = (int **)ft_strtabnew(y, x * sizeof(int) - 1)))
		return (1);
	return (0);
}
