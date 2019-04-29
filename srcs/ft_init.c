/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 01:17:29 by flcarre           #+#    #+#             */
/*   Updated: 2019/04/29 18:49:37 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_init(t_data *data)
{
	(void)data;
	data->m.p = (void *)0;
	data->m.x = 0;
	data->m.y = 0;
	data->p.p = (void *)0;
	data->p.x = 0;
	data->p.y = 0;
	data->i.p = (void *)0;
	data->i.x = 0;
	data->i.y = 0;
	data->me = 0;
	data->ad = 0;
	data->px = 0;
	data->py = 0;
}
