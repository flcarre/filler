/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:56:53 by lutsiara          #+#    #+#             */
/*   Updated: 2019/03/13 16:22:52 by lutsiara         ###   ########.fr       */
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
		free((*as)[i++]);
	free(*as);
	*as = (void *)0;
	return ((void *)0);
}
