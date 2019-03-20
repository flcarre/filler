/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iputnwstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:49:10 by lutsiara          #+#    #+#             */
/*   Updated: 2019/03/06 23:43:01 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

long	ft_iputnwstr(int *ws, unsigned long n)
{
	long			i;
	long			r;
	unsigned long	t;

	i = 0;
	if (!ws || !n)
		return (i);
	while (n && *ws)
	{
		t = ft_wcharlen(*ws);
		if (n >= t && (r = ft_iputwchar(*ws)) != -1)
			i += r;
		else if (r == -1)
			return (r);
		n -= n < t ? n : t;
		ws++;
	}
	return (i);
}
