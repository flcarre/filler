/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simuldnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:17:57 by lutsiara          #+#    #+#             */
/*   Updated: 2019/03/07 07:31:09 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <float.h>

static void	ft_fill_tx3(unsigned int *p[4], int exp)
{
	int				min;
	unsigned int	cy[2];

	while (exp < 0 && (min = (9 <= -exp) ? 9 : -exp))
	{
		cy[0] = 0;
		p[3] = p[1];
		while (p[3] < p[0])
		{
			cy[1] = *p[3] & ((1 << min) - 1);
			*p[3] = (*p[3] >> min) + cy[0];
			cy[0] = (1000000000 >> min) * cy[1];
			p[3]++;
		}
		(!(*p[1])) ? p[1]++ : 0;
		(cy[0]) ? (*(p[0]++) = cy[0]) : 0;
		exp += min;
	}
}

static void	ft_fill_tx2(unsigned int *p[4], int exp)
{
	int				min;
	unsigned int	c;
	unsigned long	y;

	while (exp > 0 && (min = (29 <= exp) ? 29 : exp))
	{
		c = 0;
		p[3] = p[0] - 1;
		while (p[3] >= p[1])
		{
			y = ((unsigned long)*p[3] << min) + c;
			*p[3] = y % 1000000000;
			c = y / 1000000000;
			p[3]--;
		}
		(c) ? (*(--p[1]) = c) : 0;
		while (p[0] > p[1] && !p[0][-1])
			p[0]--;
		exp -= min;
	}
	ft_fill_tx3(p, exp);
}

static void	ft_fill_tx(long double x, unsigned int *tx, \
			unsigned long size1, unsigned int *p[4])
{
	int				exp;
	int				i;

	x = (ft_signbit(0, &x)) ? -x : x;
	x = ft_ldfrexp(x, &exp) * 2;
	(x) ? exp-- : 0;
	(x) ? (exp -= 28) : 0;
	(x) ? (x *= 0x1P28) : 0;
	i = 3;
	if (exp <= 0)
		while (i--)
			p[i] = tx;
	else
		while (i--)
			p[i] = tx + size1 / sizeof(*tx) - LDBL_MANT_DIG - 1;
	i = 1;
	while (i || x)
	{
		(i) ? i-- : 0;
		*p[0] = x;
		x = 1000000000 * (x - (*(p[0]++)));
	}
	ft_fill_tx2(p, exp);
}

static void	ft_simu(unsigned int *p[4], t_id *e, long *r, char *s)
{
	char	buf[9 + 1];

	while (r[1] >= 0 && p[3] <= p[2])
	{
		s = ft_ull(*p[3], buf + 9);
		if ((p[3]++) != p[1])
			while (s > buf)
				*(--s) = '0';
		else if (s == buf + 9)
			*(--s) = '0';
		((r[1] = buf + 9 - s) >= 0) ? (r[0] += r[1]) : 0;
	}
	(r[1] >= 0 && (e->p[0] || (e->fm & 16) == 16) && \
	(r[1] = 1) >= 0) ? (r[0] += r[1]) : 0;
	while (r[1] >= 0 && p[3] < p[0] && e->p[0])
	{
		s = ft_ull(*(p[3]++), buf + 9);
		while (s > buf)
			*(--s) = '0';
		if ((r[1] = (9 <= e->p[0]) ? 9 : e->p[0]) >= 0)
			r[0] += r[1];
		e->p[0] -= (9 <= e->p[0]) ? 9 : e->p[0];
	}
	(r[1] = e->p[0]) >= 0 ? (r[0] += r[1]) : 0;
}

long		ft_simuldnbr(long double x, t_id *e)
{
	unsigned int	tx[SIZE_LD_TX];
	unsigned int	*p[4];
	long			r[2];
	t_id			et;

	et.p[0] = e->p[0];
	et.fm = e->fm;
	ft_bzero((void *)r, 2 * sizeof(long));
	ft_bzero((void *)tx, SIZE_LD_TX * sizeof(unsigned int));
	(ft_isinf(x) || ft_isnan(x)) ? (r[0] = 3) : 0;
	if (ft_isnan(x) || ft_isinf(x))
		return (r[0]);
	ft_fill_tx(x, tx, sizeof(tx), p);
	ft_dorounding(p, &et);
	while (p[0] > p[1] && !p[0][-1])
		p[0]--;
	(p[1] > p[2]) ? (p[1] = p[2]) : 0;
	p[3] = p[1];
	ft_simu(p, &et, r, (void *)0);
	r[0] = (r[1] < 0) ? r[1] : r[0];
	return (r[0]);
}
