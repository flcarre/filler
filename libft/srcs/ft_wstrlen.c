/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:33:53 by lutsiara          #+#    #+#             */
/*   Updated: 2019/03/06 21:28:37 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_wstrlen(const int *ws)
{
	unsigned long	i;
	unsigned long	len;

	i = 0;
	len = 0;
	while (*(ws + i))
	{
		i++;
		len += ft_wcharlen(*(ws + i));
	}
	return (len);
}
