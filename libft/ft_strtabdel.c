/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:56:53 by flcarre           #+#    #+#             */
/*   Updated: 2019/04/29 18:56:11 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_strtabdel(char ***as)
{
	unsigned long	i;

	if (!as || !(*as) || !(**as))
		return ((void *)0);
	i = 0;
	while ((*as)[i])
	{
		if ((*as)[i])
			ft_memdel((void **)&((*as)[i++]));
		else
			i++;
	}
	ft_memdel((void **)&(*as));
	return ((void *)0);
}
