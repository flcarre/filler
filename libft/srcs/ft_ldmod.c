/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldmod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:51:34 by lutsiara          #+#    #+#             */
/*   Updated: 2018/12/29 22:02:31 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double		ft_ldmod(long double x, long double mod)
{
	long double		res;
	long double		dif;
	int				er;
	int				em;

	if (mod == 0.0)
		return (0.0);
	res = ft_ldabs(x);
	mod = ft_ldabs(mod);
	ft_ldfrexp(mod, &em);
	while (res >= mod)
	{
		ft_ldfrexp(res, &er);
		dif = ft_ldexp(mod, er - em);
		res -= (dif <= res) ? dif : dif * ((long double)0.5);
	}
	return ((x < ((long double)0.0)) ? -res : res);
}
