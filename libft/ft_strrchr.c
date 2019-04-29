/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:44:22 by flcarre           #+#    #+#             */
/*   Updated: 2019/04/29 18:55:50 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned long	i;

	if (!s)
		return ((void *)0);
	i = ft_strlen(s) + 1;
	while (i--)
		if (*(s + i) == (char)c)
			return ((char *)(s + i));
	return ((void *)0);
}
