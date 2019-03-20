/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldexp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:56:04 by lutsiara          #+#    #+#             */
/*   Updated: 2018/12/29 22:11:00 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include "libft.h"

long double		ft_ldexp(long double x, int e)
{
	int		oe;

	if (e == 0 || x == 0.0)
		return (x);
	ft_ldfrexp(x, &oe);
	if (e > 0)
	{
		if (e + oe > LDBL_MAX_EXP)
			return ((x < 0.0) ? -LDBL_MAX : LDBL_MAX);
		while (e > 62)
		{
			x *= (1LL << 62);
			e -= 62;
		}
		return (x * (1LL << e));
	}
	if (e + oe < LDBL_MIN_EXP)
		return (0.0);
	while (e < -62)
	{
		x *= 1.0 / (1LL << 62);
		e += 62;
	}
	return (x / (1LL << -e));
}
