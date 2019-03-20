/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 18:27:56 by lutsiara          #+#    #+#             */
/*   Updated: 2019/03/20 01:12:08 by lutsiara         ###   ########.fr       */
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
	if (ft_getmap(&data.m))
		return (1);
	while (!end)
	{
		ft_getpiece(&data.p);
		end = ft_fight(&data);
		if (end)
			ft_free(&data);
		else
			ft_updatemap(&data.m);
	}
	return (0);
}
