/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 18:27:56 by lutsiara          #+#    #+#             */
/*   Updated: 2019/03/20 08:33:56 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_data	data;
	int		end;

	end = 0;
	ft_init(&data);
	ft_whoami(&data);
	if (ft_getmap(&data.m) || ft_alloccalc(&data))
		return (1);
	while (!end)
	{
		if (ft_getpiece(&data.p))
			return (1);
		end = ft_fight(&data);
		if (end)
			ft_free(&data);
		else
			ft_updatemap(&data.m);
	}
	return (0);
}
