/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dfrexp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:26:14 by lutsiara          #+#    #+#             */
/*   Updated: 2018/12/28 21:46:52 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ieee.h"

double		ft_dfrexp(double x, int *p)
{
	t_u_ieee_d		u;

	if (x)
	{
		u.d = x;
		if (u.sd.e != D_EXP_INFNAN)
		{
			*p = u.sd.e - (D_EXP_BIAS - 1);
			u.sd.e = D_EXP_BIAS - 1;
		}
		return (u.d);
	}
	*p = 0;
	return (0.0);
}
