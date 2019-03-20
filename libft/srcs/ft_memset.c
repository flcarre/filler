/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:52:23 by lutsiara          #+#    #+#             */
/*   Updated: 2018/12/28 22:38:42 by lutsiara         ###   ########.fr       */
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
