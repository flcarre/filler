/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fight.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 04:16:03 by lutsiara          #+#    #+#             */
/*   Updated: 2019/03/25 21:21:56 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_fight(t_data *data)
{
	ft_calcmap(data);
	if (ft_tracking(data))
	{
		ft_putunbr(data->px);
		ft_putchar(' ');
		ft_putunbr(data->py);
		ft_putchar('\n');
		return (1);
	}
	ft_putunbr(data->px);
	ft_putchar(' ');
	ft_putunbr(data->py);
	ft_putchar('\n');
	ft_resetmap(&data->i);
	return (0);
}
