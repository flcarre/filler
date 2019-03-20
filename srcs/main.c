/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flxw <flxw@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 18:27:56 by lutsiara          #+#    #+#             */
/*   Updated: 2019/03/20 03:00:18 by flxw             ###   ########.fr       */
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
	//while (!end)
	//{
		ft_getpiece(&data.p);
	//	end = ft_fight(&data);
	//	if (end)
	//		ft_free(&data);
	//	else
	//		ft_updatemap(&data.m);
	//}
	ft_putnbr_fd(data.m.y, 2);
	ft_putendl_fd("", 2);
	ft_putnbr_fd(data.m.x, 2);
	ft_putendl_fd("", 2);
	ft_printab_fd(data.m.p, 2);
	ft_putendl_fd("", 2);
	ft_putnbr_fd(data.p.y, 2);
	ft_putendl_fd("", 2);
	ft_putnbr_fd(data.p.x, 2);
	ft_putendl_fd("", 2);
	ft_printab_fd(data.p.p, 2);
	ft_putendl_fd("", 2);
	return (0);
}
