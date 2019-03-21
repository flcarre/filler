/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:56:53 by lutsiara          #+#    #+#             */
/*   Updated: 2019/03/20 09:16:16 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_strtabdel(char ***as)
{
	unsigned long	i;

	if (!(*as))
		return ((void *)0);
	i = 0;
	while ((*as)[i])
	{
		if ((*as)[i])
		{
			free((*as)[i]);
			(*as)[i++] = (void *)0;
		}
		else
			i++;
	}
	free(*as);
	*as = (void *)0;
	return ((void *)0);
}
