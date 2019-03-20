/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fight.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 04:16:03 by lutsiara          #+#    #+#             */
/*   Updated: 2019/03/20 05:49:13 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <unistd.h>

int		ft_fight(t_data *data)
{
	//ft_calcmap(&data->i, &data->m);
	//if (ft_backtrack(data))
	//	return (1);
	ft_putunbr(data->px);
	ft_putchar(' ');
	ft_putunbr(data->py);
	write(1, "\n", 1);
	//ft_resetmap(&data->i);
	return (0);
}
