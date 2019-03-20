/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:41:39 by lutsiara          #+#    #+#             */
/*   Updated: 2019/03/13 16:23:45 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*cpy;

	if (!(cpy = (char *)ft_strnew(ft_strlen(s1))))
		return ((void *)0);
	ft_memcpy((void *)cpy, (const void *)s1, ft_strlen(s1));
	return (cpy);
}
