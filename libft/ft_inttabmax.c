/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inttabmax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 23:07:22 by lutsiara          #+#    #+#             */
/*   Updated: 2019/03/20 23:15:35 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_inttabmax(int ***tab, unsigned int x, unsigned int y)
{
	unsigned int	i;
	unsigned int	j;
	int				max;

	i = 0;
	max = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if ((*tab)[i][j] > max)
				max = (*tab)[i][j];
			j++;
		}
		i++;
	}
	return (max);
}
