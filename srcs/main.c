/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 18:27:56 by flcarre           #+#    #+#             */
/*   Updated: 2019/04/29 18:50:12 by flcarre          ###   ########.fr       */
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

__attribute__((destructor)) int end()
{
	while(1);
}
