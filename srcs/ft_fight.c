/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fight.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 04:16:03 by lutsiara          #+#    #+#             */
/*   Updated: 2019/04/12 16:41:17 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_fight(t_data *data)
{
	ft_calcmap(data);
	if (ft_tracking(data))
	{
		ft_putnbr(data->px);
		ft_putchar(' ');
		ft_putnbr(data->py);
		ft_putchar('\n');
		return (1);
	}
	ft_putnbr(data->px);
	ft_putchar(' ');
	ft_putnbr(data->py);
	ft_putchar('\n');
	ft_resetmap(&data->i);
	if (data->p.p)
	{
		ft_strtabdel(&data->p.p);
		data->p.p = (void *)0;
	}
	return (0);
}
