/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:23:54 by flcarre           #+#    #+#             */
/*   Updated: 2019/04/29 18:56:17 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned long	len;
	unsigned long	i;
	char			*tmp;

	if (!s)
		return (ft_strnew(0));
	len = ft_strlen(s);
	while (len && ft_iswhitespace((int)(*(s + len - 1))))
		len--;
	while (len && ft_iswhitespace((int)(*s)))
	{
		s++;
		len--;
	}
	if (!(tmp = ft_strnew(len)))
		return ((void *)0);
	i = 0;
	while (len--)
		*(tmp + (i++)) = *(s++);
	return (tmp);
}
