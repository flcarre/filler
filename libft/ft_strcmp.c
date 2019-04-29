/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:21:08 by flcarre           #+#    #+#             */
/*   Updated: 2019/04/29 18:55:01 by flcarre          ###   ########.fr       */
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
