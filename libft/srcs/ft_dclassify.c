/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dclassify.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:51:22 by lutsiara          #+#    #+#             */
/*   Updated: 2019/01/21 20:06:28 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include <math.h>
#include "ft_ieee.h"

int		ft_dclassify(double x)
{
	t_u_ieee_d		u;

	u.d = x;
	if (u.sd.e == 0)
	{
		if ((u.sd.fl | u.sd.fh) == 0)
			return (FP_ZERO);
		return (FP_SUBNORMAL);
	}
	if (u.sd.e == D_EXP_INFNAN)
	{
		if ((u.sd.fl | u.sd.fh) == 0)
			return (FP_INFINITE);
		return (FP_NAN);
	}
	return (FP_NORMAL);
}
