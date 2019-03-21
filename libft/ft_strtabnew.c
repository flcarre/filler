/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:50:00 by lutsiara          #+#    #+#             */
/*   Updated: 2019/03/20 08:51:42 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_strtabnew(unsigned long y, unsigned long x)
{
	char			**tmp;
	unsigned long	i;

	if (!(tmp = (char **)malloc(sizeof(char *) * (y + 1))))
		return ((void *)0);
	i = 0;
	while (i <= y)
		*(tmp + (i++)) = (void *)0;
	i = 0;
	while (x && i < y)
		if (!(*(tmp + (i++)) = ft_strnew(x)))
			return (ft_strtabdel(&tmp));
	return (tmp);
}
