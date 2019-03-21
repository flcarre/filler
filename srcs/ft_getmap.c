/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 03:46:22 by lutsiara          #+#    #+#             */
/*   Updated: 2019/03/20 08:35:53 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	ft_check_map(t_tab *m, unsigned int j)
{
	unsigned long	i;

	i = 0;
	while (m->p[j][i])
	{
		if (m->p[j][i] != '.' && m->p[j][i] != 'O' && m->p[j][i] != 'X')
		{
			ft_strtabdel(&m->p);
			return (1);
		}
		i++;
	}
	return (0);
}

int			ft_getmap(t_tab *m)
{
	char			*s;
	unsigned int	i;

	i = 0;
	s = (void *)0;
	get_next_line(0, &s);
	m->y = ft_atoui(ft_strchr(s, ' '));
	m->x = ft_atoui(ft_strchr(ft_strchr(s, ' ') + 1, ' '));
	ft_memdel((void **)&s);
	if (!(m->p = ft_strtabnew(m->y, m->x)))
		return (1);
	get_next_line(0, &s);
	while (m->p[i])
	{
		ft_memdel((void **)&s);
		get_next_line(0, &s);
		ft_strcpy(m->p[i], ft_strchr(s, ' ') + 1);
		if (ft_check_map(m, i++))
		{
			ft_memdel((void **)&s);
			return (1);
		}
	}
	ft_memdel((void **)&s);
	return (0);
}
