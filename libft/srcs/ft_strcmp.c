/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:21:08 by lutsiara          #+#    #+#             */
/*   Updated: 2018/11/14 13:56:42 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned long	len;

	len = (ft_strlen(s1) <= ft_strlen(s2)) ? ft_strlen(s1) : ft_strlen(s2);
	len += 1;
	return (ft_memcmp((const void *)s1, (const void *)s2, len));
}
