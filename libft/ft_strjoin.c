/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:02:30 by flcarre           #+#    #+#             */
/*   Updated: 2019/04/29 18:55:20 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*tmp;
	unsigned long	i;
	unsigned long	len;

	len = 0;
	if (!s1 && !s2)
		return ((void *)0);
	else if (!s1)
		len = ft_strlen(s2);
	else if (!s2)
		len = ft_strlen(s1);
	else
		len = ft_strlen(s1) + ft_strlen(s2);
	if (!(tmp = ft_strnew(len)))
		return ((void *)0);
	i = 0;
	while (s1 && *s1)
		*(tmp + (i++)) = *(s1++);
	while (s2 && *s2)
		*(tmp + (i++)) = *(s2++);
	return (tmp);
}
