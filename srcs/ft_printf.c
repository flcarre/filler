/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 18:04:14 by lutsiara          #+#    #+#             */
/*   Updated: 2019/02/25 17:29:08 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	ft_p(char **format, unsigned long n, int *r)
{
	long	ret;

	if ((ret = write(1, (*format), n)) < 0)
		return (-1);
	*format += n;
	*r += (int)ret;
	return (ret);
}

int			ft_printf(const char *format, ...)
{
	va_list	args;
	int		r;
	char	*s;

	r = 0;
	va_start(args, format);
	while (*format)
	{
		s = ft_strchr(format, '%');
		if (s && ft_p((char **)&format, s - format, &r) < 0)
			return (-1);
		else if (!s)
			ft_p((char **)&format, ft_strlen(format), &r);
		if (*format == '%' && ft_converter((char **)&format, args, &r))
			return (-1);
	}
	va_end(args);
	return (r);
}
