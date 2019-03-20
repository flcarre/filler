/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:45:47 by lutsiara          #+#    #+#             */
/*   Updated: 2018/12/28 21:00:35 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long	r;
	long	n;

	r = 0;
	n = 1;
	while (ft_isspace((int)(*str)))
		str++;
	n = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit((int)(*str)))
		r = r * 10 + *(str++) - '0';
	return ((int)(r * n));
}
