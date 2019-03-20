/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:00:06 by lutsiara          #+#    #+#             */
/*   Updated: 2018/12/28 22:34:57 by lutsiara         ###   ########.fr       */
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
