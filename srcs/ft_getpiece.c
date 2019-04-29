/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpiece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 03:47:11 by flcarre           #+#    #+#             */
/*   Updated: 2019/04/29 18:49:22 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	ft_check_piece(t_tab *m, char *s)
{
	unsigned long	i;

	i = 0;
	if ((unsigned long)m->x != ft_strlen(s))
		return (1);
	while (s[i])
	{
		if (s[i] != '.' && s[i] != '*')
			return (1);
		i++;
	}
	return (0);
}

static int	ft_getsize(t_tab *m)
{
	char			*s;
	char			*tmp;
	int				r;

	s = (void *)0;
	r = 0;
	if (get_next_line(0, &s) != 1)
		return (1);
	if (!r && !(tmp = ft_strstr(s, "Piece")))
		r = 1;
	if (!r && !(tmp = ft_strchr(s, ' ')))
		r = 1;
	m->y = (!r) ? ft_atoui(tmp) : 0;
	if (!r && !(tmp = ft_strchr(tmp + 1, ' ')))
		r = 1;
	m->x = (!r) ? ft_atoui(tmp) : 0;
	if (!r && ft_strchr(tmp + 1, ' '))
		r = 1;
	if (!r && !(tmp = ft_strchr(tmp, ':')))
		r = 1;
	if (!r && *(tmp + 1))
		r = 1;
	ft_memdel((void **)&s);
	return (r);
}

int			ft_getpiece(t_tab *p)
{
	char			*s;
	unsigned int	i;

	s = (void *)0;
	i = 0;
	if (ft_getsize(p))
		return (1);
	if (!(p->p = ft_strtabnew(p->y, p->x)))
		return (1);
	while (p->p[i])
	{
		if (get_next_line(0, &s) != 1)
			return (1);
		if (ft_check_piece(p, s))
		{
			ft_memdel((void **)&s);
			return (1);
		}
		ft_strcpy(p->p[i], s);
		ft_memdel((void **)&s);
		i++;
	}
	return (0);
}
