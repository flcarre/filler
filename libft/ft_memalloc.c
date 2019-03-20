/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:05:15 by lutsiara          #+#    #+#             */
/*   Updated: 2019/03/13 16:25:04 by lutsiara         ###   ########.fr       */
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
