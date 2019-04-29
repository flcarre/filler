/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:25:10 by flcarre           #+#    #+#             */
/*   Updated: 2019/04/29 18:54:08 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dst, const void *src, unsigned long n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	*start;

	if (!n)
		return (dst);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	start = (unsigned char *)src;
	while ((unsigned long)(s - start) < n)
		*(d++) = *(s++);
	return (dst);
}
