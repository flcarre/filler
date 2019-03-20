/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iputnbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 12:26:24 by lutsiara          #+#    #+#             */
/*   Updated: 2019/02/20 14:38:59 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_iputnbr_base(long long n, char *base)
{
	unsigned long long	x;
	long				i;
	long				r;
	unsigned long		b;

	i = 0;
	b = ft_strlen(base);
	x = (n < 0) ? -n : n;
	if (n < 0)
	{
		if ((r = ft_iputchar('-')) != -1)
			i += r;
		else
			return (r);
	}
	if (x >= (unsigned long long)b)
	{
		((r = ft_iputnbr_base(x / b, base)) >= 0) ? (i += r) : 0;
		(r >= 0 && (r = ft_iputnbr_base(x % b, base)) >= 0) ? (i += r) : 0;
	}
	else
		((r = ft_iputchar(base[x])) >= 0) ? (i += r) : 0;
	return ((r == -1) ? r : i);
}
