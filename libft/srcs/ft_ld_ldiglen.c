/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld_ldiglen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:07:54 by lutsiara          #+#    #+#             */
/*   Updated: 2019/03/07 07:42:12 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_ld_ldiglen(long double n, long double base)
{
	unsigned int	len;

	if (ft_isinf(n) || ft_isnan(n))
		return (0);
	if (ft_ldmod(base, 1.0L) != 0.0L || base < 2.0L)
		return (0);
	len = (n < 1.0L && n > -1.0L) ? 1 : 0;
	while (n >= 1.0L || n <= -1.0L)
	{
		len++;
		n /= base;
	}
	return (len);
}
