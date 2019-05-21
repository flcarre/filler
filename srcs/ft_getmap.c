/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 03:46:22 by flcarre           #+#    #+#             */
/*   Updated: 2019/05/21 18:16:14 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	ft_check_map(t_tab *m, char *s)
{
	unsigned long	i;
	char			r;

	i = 0;
	r = 0;
	if ((unsigned long)m->x + 4 != ft_strlen(s))
		return (1);
	while (s[i])
	{
		r = i < 3 && !ft_isdigit(s[i]) ? 1 : r;
		if (i == 3 && s[i] != ' ')
			return (1);
		if ((i > 3 && s[i] != '.' && s[i] != 'O' && s[i] != 'X') || r == 1)
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
	if (gnl(0, &s) != 1)
		return (1);
	if (!r && !(tmp = ft_strstr(s, "Plateau")))
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

static int	ft_line_check(t_tab *m, char **s)
{
	unsigned long	i;

	i = 0;
	if ((unsigned long)m->x + 4 != ft_strlen(*s))
	{
		ft_memdel((void **)&(*s));
		return (1);
	}
	while ((*s)[i])
	{
		while ((*s)[i] && i < 4)
			if ((*s)[i++] != ' ')
			{
				ft_memdel((void **)&(*s));
				return (1);
			}
		if ((*s)[i] && !ft_isdigit((int)(*s)[i]))
		{
			ft_memdel((void **)&(*s));
			return (1);
		}
		i += ((*s)[i]) ? 1 : 0;
	}
	return (0);
}

int			ft_getmap(t_tab *m)
{
	char			*s;
	unsigned int	i;

	i = 0;
	s = (void *)0;
	if (ft_getsize(m))
		return (1);
	if (!(m->p = ft_strtabnew(m->y, m->x)) || gnl(0, &s) != 1 || \
	ft_line_check(m, &s))
		return (1);
	while (m->p[i])
	{
		ft_memdel((void **)&s);
		if (gnl(0, &s) != 1)
			return (1);
		if (ft_check_map(m, s))
		{
			ft_memdel((void **)&s);
			return (1);
		}
		ft_strcpy(m->p[i++], ft_strchr(s, ' ') + 1);
	}
	ft_memdel((void **)&s);
	return (0);
}
