/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iputstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 12:07:24 by lutsiara          #+#    #+#             */
/*   Updated: 2019/03/06 16:58:06 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

long	ft_iputstr(char const *s)
{
	long	i;
	long	r;

	i = 0;
	if (!s)
		return (i);
	if ((r = write(1, s, ft_strlen(s))) != -1)
		i += r;
	else
		return (r);
	return (i);
}
