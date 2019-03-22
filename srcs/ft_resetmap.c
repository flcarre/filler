/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resetmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 06:11:35 by lutsiara          #+#    #+#             */
/*   Updated: 2019/03/22 06:19:57 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_resetmap(t_tac *i)
{
	unsigned int	y;
	unsigned int	x;

	y = 0;
	while (y < i->y)
	{
		x = 0;
		while (x < i->x)
			i->p[y][x++] = 0;
		y++;
	}
}
