/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 13:52:26 by lutsiara          #+#    #+#             */
/*   Updated: 2019/03/13 16:23:24 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*tmp;
	unsigned long	i;

	if (!s || !f)
		return ((void *)0);
	if (!(tmp = ft_strnew(ft_strlen(s))))
		return ((void *)0);
	i = 0;
	while (*s)
		*(tmp + (i++)) = f(*(s++));
	return (tmp);
}
