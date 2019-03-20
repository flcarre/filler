/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldfrexp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:55:12 by lutsiara          #+#    #+#             */
/*   Updated: 2018/12/28 22:09:53 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ieee.h"

long double		ft_ldfrexp(long double x, int *p)
{
	t_u_ieee_ld		u;

	if (x)
	{
		u.ld = x;
		if (u.sld.e != LD_EXP_INFNAN)
		{
			*p = u.sld.e - (LD_EXP_BIAS - 1);
			u.sld.e = LD_EXP_BIAS - 1;
		}
		return (u.ld);
	}
	*p = 0;
	return (0.0);
}
