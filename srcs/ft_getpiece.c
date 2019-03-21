/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpiece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 03:47:11 by lutsiara          #+#    #+#             */
/*   Updated: 2019/03/20 08:59:58 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	ft_getpiece(t_tab *p)
{
	char			*s;
	unsigned int	i;

	s = (void *)0;
	i = 0;
	get_next_line(0, &s);
	p->y = ft_atoui(ft_strchr(s, ' '));
	p->x = ft_atoui(ft_strchr(ft_strchr(s, ' ') + 1, ' '));
	ft_memdel((void **)&s);
	if (!(p->p = ft_strtabnew(p->y, p->x)))
		return (1);
	while (p->p[i])
	{
		get_next_line(0, &s);
		ft_strcpy(p->p[i], s);
		ft_memdel((void **)&s);
		i++;
	}
	return (0);
}
