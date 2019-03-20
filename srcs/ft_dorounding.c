/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dorounding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:14:55 by lutsiara          #+#    #+#             */
/*   Updated: 2019/03/07 06:39:22 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <float.h>

static void	ft_process(unsigned int *p[4], unsigned int x, unsigned int i)
{
	long double		r[2];

	r[0] = 2 / LDBL_EPSILON;
	if (((*p[3] / i) & 1) || (i == 1000000000 && p[3] > p[1] && (p[3][-1] & 1)))
		r[0] += 2;
	if (x < i / 2)
		r[1] = 0x0.8p0;
	else if (x == i / 2 && p[3] + 1 == p[0])
		r[1] = 0x1.0p0;
	else
		r[1] = 0x1.8p0;
	*p[3] -= x;
	if (r[0] + r[1] != r[0])
	{
		*p[3] = *p[3] + i;
		while (*p[3] > 999999999)
		{
			*(p[3]--) = 0;
			(p[3] < p[1]) ? (*(--p[1]) = 0) : 0;
			(*p[3])++;
		}
	}
}

void		ft_dorounding(unsigned int *p[4], t_id *e)
{
	int				pr;
	unsigned int	i;
	unsigned int	x;

	pr = (int)e->p[0];
	if (pr < 9 * (p[0] - p[2] - 1))
	{
		p[3] = p[2] + 1 + ((pr + 9 * LDBL_MAX_EXP) / 9 - LDBL_MAX_EXP);
		pr += 9 * LDBL_MAX_EXP;
		pr %= 9;
		i = 10;
		pr++;
		while (pr < 9)
		{
			i *= 10;
			pr++;
		}
		x = *p[3] % i;
		if (x || p[3] + 1 != p[0])
			ft_process(p, x, i);
		(p[0] > p[3] + 1) ? (p[0] = p[3] + 1) : 0;
	}
}
