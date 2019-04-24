/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 18:27:56 by lutsiara          #+#    #+#             */
/*   Updated: 2019/04/23 18:11:38 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			main(void)
{
	t_data	data;
	int		end;

	end = 0;
	ft_init(&data);
	if (ft_whoami(&data))
		return (1);
	if (ft_getmap(&data.m) || ft_alloccalc(&data))
	{
		ft_free(&data);
		return (1);
	}
	while (!end)
	{
		if (ft_getpiece(&data.p) && ft_free(&data))
			return (1);
		end = ft_fight(&data);
		if (end)
			ft_free(&data);
		else if (ft_updatemap(&data.m) && ft_free(&data))
			return (1);
	}
	return (0);
}
