/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:52:23 by flcarre           #+#    #+#             */
/*   Updated: 2019/04/29 18:54:20 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *b, int c, unsigned long len)
{
	unsigned char	*p;
	unsigned char	*s;

	p = (unsigned char *)b;
	s = (unsigned char *)b;
	while ((unsigned long)(p - s) < len)
		*(p++) = (unsigned char)c;
	return (b);
}
