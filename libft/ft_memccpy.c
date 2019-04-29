/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:08:37 by flcarre           #+#    #+#             */
/*   Updated: 2019/04/29 18:53:58 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memccpy(void *dst, const void *src, int c, unsigned long n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	*start;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	start = (unsigned char *)src;
	while ((unsigned long)(s - start) < n)
	{
		*(d++) = *s;
		if (*s == (unsigned char)c)
			return ((void *)d);
		s++;
	}
	return ((void *)0);
}
