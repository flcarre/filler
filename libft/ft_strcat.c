/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:03:54 by lutsiara          #+#    #+#             */
/*   Updated: 2019/03/13 16:24:00 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	unsigned long	i;

	i = ft_strlen((const char *)s1);
	while (*s2)
		*(s1 + (i++)) = *(s2++);
	*(s1 + i) = '\0';
	return (s1);
}
