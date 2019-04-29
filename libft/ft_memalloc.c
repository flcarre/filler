/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:05:15 by flcarre           #+#    #+#             */
/*   Updated: 2019/04/29 18:53:55 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(unsigned long size)
{
	unsigned char	*mem;

	if (!size)
		return ((void *)0);
	if (!(mem = (unsigned char *)malloc(sizeof(unsigned char) * size)))
		return ((void *)0);
	ft_bzero((void *)mem, size);
	return ((void *)mem);
}
