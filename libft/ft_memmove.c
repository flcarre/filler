/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:48:13 by flcarre           #+#    #+#             */
/*   Updated: 2019/04/29 18:54:17 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, unsigned long len)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	*start;
	unsigned char	*tmp;

	if (!len)
		return (dst);
	if (!(tmp = (unsigned char *)ft_memalloc(sizeof(unsigned char) * len)))
		return (dst);
	d = tmp;
	s = (unsigned char *)src;
	start = (unsigned char *)src;
	while ((unsigned long)(s - start) < len)
		*(d++) = *(s++);
	d = (unsigned char *)dst;
	s = tmp;
	start = tmp;
	while ((unsigned long)(s - start) < len)
		*(d++) = *(s++);
	ft_memdel((void **)&tmp);
	return (dst);
}
