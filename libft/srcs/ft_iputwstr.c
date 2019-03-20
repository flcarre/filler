/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iputwstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:49:10 by lutsiara          #+#    #+#             */
/*   Updated: 2019/03/06 22:43:00 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

long	ft_iputwstr(int *ws)
{
	long	i;
	long	r;

	i = 0;
	if (!ws)
		return (i);
	while (*ws)
	{
		if ((r = ft_iputwchar(*(ws++))) != -1)
			i += r;
		else
			return (r);
	}
	return (i);
}
