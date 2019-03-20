/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpiece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 03:47:11 by lutsiara          #+#    #+#             */
/*   Updated: 2019/03/20 03:59:30 by lutsiara         ###   ########.fr       */
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
	if (!(p->p = ft_strtabnew(p->y, p->x)))
		return (1);
	while (p->p[i])
	{
		ft_memdel((void **)&s);
		get_next_line(0, &s);
		ft_strcpy(p->p[i], s);
		i++;
	}
	ft_memdel((void **)&s);
	return (0);
}
