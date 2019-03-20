/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dmod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:56:19 by lutsiara          #+#    #+#             */
/*   Updated: 2018/12/28 21:47:52 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_dmod(double x, double mod)
{
	double	res;
	double	dif;
	int		er;
	int		em;

	if (mod == 0.0)
		return (0.0);
	res = ft_dabs(x);
	mod = ft_dabs(mod);
	ft_dfrexp(mod, &em);
	while (res >= mod)
	{
		ft_dfrexp(res, &er);
		dif = ft_dexp(mod, er - em);
		res -= (dif <= res) ? dif : dif * ((double)0.5);
	}
	return ((x < ((double)0.0)) ? -res : res);
}
