/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signbit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 23:41:11 by lutsiara          #+#    #+#             */
/*   Updated: 2019/01/23 23:06:09 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ieee.h"

static int	x_signbit(double x)
{
	t_u_ieee_d	u;

	u.d = x;
	return (u.sd.s);
}

static int	lx_signbit(long double lx)
{
	t_u_ieee_ld	u;

	u.ld = lx;
	return (u.sld.s);
}

int			ft_signbit(double *x, long double *lx)
{
	if (x)
		return (x_signbit(*x));
	if (lx)
		return (lx_signbit(*lx));
	return (0);
}
