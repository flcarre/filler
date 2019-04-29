/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:00:06 by flcarre           #+#    #+#             */
/*   Updated: 2019/04/29 18:54:02 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *s, int c, unsigned long n)
{
	unsigned char	*p;
	unsigned char	*start;

	if (!n)
		return ((void *)0);
	p = (unsigned char *)s;
	start = (unsigned char *)s;
	while ((unsigned long)(p - start) < n)
	{
		if (*p == (unsigned char)c)
			return ((void *)p);
		p++;
	}
	return ((void *)0);
}
