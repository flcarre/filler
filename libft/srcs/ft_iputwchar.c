/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iputwchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:42:17 by lutsiara          #+#    #+#             */
/*   Updated: 2019/03/06 21:44:10 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_iputwchar(int wc)
{
	char	c[5];

	ft_bzero((void *)c, 5);
	if (wc <= 0x7F)
		return ((ft_iputchar((char)wc) >> 63) ? -1 : 1);
	else if (wc <= 0x7FF)
	{
		c[0] = (wc >> 6) + 0xC0;
		c[1] = (wc & 0x3F) + 0x80;
	}
	else if (wc <= 0xFFFF)
	{
		c[0] = (wc >> 12) + 0xE0;
		c[1] = ((wc >> 6) & 0x3F) + 0x80;
		c[2] = (wc & 0x3F) + 0x80;
	}
	else
	{
		c[0] = (wc >> 18) + 0xF0;
		c[1] = ((wc >> 12) & 0x3F) + 0x80;
		c[2] = ((wc >> 6) & 0x3F) + 0x80;
		c[3] = (wc & 0x3F) + 0x80;
	}
	return ((ft_iputstr(c) >> 63) ? -1 : ft_wcharlen(wc));
}
