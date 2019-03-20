/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iputxchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 12:07:24 by lutsiara          #+#    #+#             */
/*   Updated: 2019/03/06 17:11:22 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

long	ft_iputxchar(char c, unsigned long x)
{
	long	i;
	long	r;
	char	b[1000];

	i = 0;
	if (!x)
		return (i);
	if (x > 999)
		return (ft_iputxchar(c, x - 999));
	ft_bzero((void *)b, 1000);
	ft_memset((void *)b, (int)c, x);
	if ((r = write(1, b, ft_strlen(b))) != -1)
		i += r;
	else
		return (r);
	return (i);
}
