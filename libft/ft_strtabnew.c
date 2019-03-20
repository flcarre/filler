/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:50:00 by lutsiara          #+#    #+#             */
/*   Updated: 2019/03/13 16:22:40 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**ft_strtabnew(unsigned long size)
{
	char	**tmp;

	if (!(tmp = (char **)malloc(sizeof(char *) * (size + 1))))
		return ((void *)0);
	*(tmp + size) = (void *)0;
	while (size--)
		*(tmp + size) = (void *)0;
	return (tmp);
}
