/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_updatemap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 03:47:18 by lutsiara          #+#    #+#             */
/*   Updated: 2019/03/20 03:54:54 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_updatemap(t_tab *m)
{
	char	*s;
	int		i;

	s = (void *)0;
	i = 0;
	get_next_line(0, &s);
	ft_memdel((void **)&s);
	get_next_line(0, &s);
	while (m->p[i])
	{
		ft_memdel((void **)&s);
		get_next_line(0, &s);
		ft_strcpy(m->p[i], ft_strchr(s, ' ') + 1);
		i++;
	}
	ft_memdel((void **)&s);
}
