/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:36:42 by lutsiara          #+#    #+#             */
/*   Updated: 2019/04/04 18:37:46 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned long	i;

	if (!s)
		return ((void *)0);
	i = ft_strlen(s) + 1;
	while (i--)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return ((void *)0);
}
