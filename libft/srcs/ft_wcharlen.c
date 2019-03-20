/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:42:17 by lutsiara          #+#    #+#             */
/*   Updated: 2019/02/27 15:40:05 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_wcharlen(int wc)
{
	unsigned long	n;

	n = 0;
	if (wc <= 0x7F)
		n = 1;
	else if (wc <= 0x7FF)
		n = 2;
	else if (wc <= 0xFFFF)
		n = 3;
	else
		n = 4;
	return (n);
}
