/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:19:57 by flcarre           #+#    #+#             */
/*   Updated: 2019/04/29 18:55:22 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_strlcat(char *dst, const char *src, unsigned long size)
{
	unsigned long	i;
	unsigned long	d;
	unsigned long	s;

	d = ft_strlen((const char *)dst);
	s = ft_strlen(src);
	if (!dst || !src || !size)
		return ((size >= d) ? d + s : s + size);
	i = 0;
	while (*src && i < ((size <= d) ? 0 : size - d - 1))
		*(dst + d + (i++)) = *(src++);
	*(dst + d + i) = '\0';
	return ((size >= d) ? d + s : s + size);
}
