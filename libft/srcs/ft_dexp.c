/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dexp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:55:29 by lutsiara          #+#    #+#             */
/*   Updated: 2018/12/28 21:45:51 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include "libft.h"

double		ft_dexp(double x, int e)
{
	int		oe;

	if (e == 0 || x == 0.0)
		return (x);
	ft_dfrexp(x, &oe);
	if (e > 0)
	{
		if (e + oe > DBL_MAX_EXP)
			return ((x < 0.0) ? -DBL_MAX : DBL_MAX);
		while (e > 62)
		{
			x *= (1L << 62);
			e -= 62;
		}
		return (x * (1L << e));
	}
	if (e + oe < DBL_MIN_EXP)
		return (0.0);
	while (e < -62)
	{
		x *= 1.0 / (1L << 62);
		e += 62;
	}
	return (x / (1L << -e));
}
