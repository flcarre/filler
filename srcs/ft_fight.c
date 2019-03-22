/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fight.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 04:16:03 by lutsiara          #+#    #+#             */
/*   Updated: 2019/03/22 06:21:02 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <unistd.h>

static void	printtab(t_tac *tab)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < tab->y) {
		j = 0;
		while (j < tab->x) {
			ft_putnbr_fd(tab->p[i][j++], 2);
			ft_putchar_fd(' ', 2);
		}
		i++;
		ft_putchar_fd('\n', 2);
	}
}

int		ft_fight(t_data *data)
{
	/*if (ft_backtrack(data, ft_calcmap(data)))
		return (1);
	*/
	ft_calcmap(data);
	printtab(&data->i);
	ft_putunbr(data->px);
	ft_putchar(' ');
	ft_putunbr(data->py);
	write(1, "\n", 1);
	ft_resetmap(&data->i);
	return (1);
}
