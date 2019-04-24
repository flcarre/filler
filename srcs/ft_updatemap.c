/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_updatemap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 03:47:18 by lutsiara          #+#    #+#             */
/*   Updated: 2019/04/23 19:11:22 by lutsiara         ###   ########.fr       */
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

static int	ft_verif_mapinfo(t_tab *m)
{
	char			*s;
	char			*tmp;
	int				r;

	s = (void *)0;
	r = 0;
	if (get_next_line(0, &s) != 1)
		return (1);
	if (!r && !(tmp = ft_strstr(s, "Plateau")))
		r = 1;
	if (!r && (!(tmp = ft_strchr(s, ' ')) || m->y != ft_atoui(tmp)))
		r = 1;
	if (!r && (!(tmp = ft_strchr(tmp + 1, ' ')) || m->x != ft_atoui(tmp)))
		r = 1;
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

int			ft_updatemap(t_tab *m)
{
	char	*s;
	int		i;

	s = (void *)0;
	i = 0;
	if (ft_verif_mapinfo(m))
		return (1);
	if (get_next_line(0, &s) != 1 || ft_line_check(m, &s))
		return (1);
	while (m->p[i])
	{
		ft_memdel((void **)&s);
		if (get_next_line(0, &s) != 1)
			return (1);
		if (ft_check_map(m, s))
		{
			ft_memdel((void **)&s);
			return (1);
		}
		ft_strcpy(m->p[i], ft_strchr(s, ' ') + 1);
		i++;
	}
	ft_memdel((void **)&s);
	return (0);
}
