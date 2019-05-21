/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whoami.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 03:47:28 by flcarre           #+#    #+#             */
/*   Updated: 2019/05/21 18:15:51 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	ft_verif_syntax(char **s)
{
	char	*tmp;
	int		r;

	r = 0;
	if (!r && !(tmp = ft_strstr(*s, "$$$ exec p")))
		r = 1;
	if (!r && tmp != *s)
		r = 1;
	if (!r && !(tmp = ft_strstr(*s + 10, " : [")))
		r = 1;
	if (!r && !(tmp = ft_strchr(tmp + 4, (int)']')))
		r = 1;
	if (!r && *(tmp + 1))
		r = 1;
	if (r)
		ft_memdel((void **)&(*s));
	return (r);
}

int			ft_whoami(t_data *data)
{
	char	*s;

	s = (void *)0;
	if (gnl(0, &s) != 1)
		return (1);
	if (ft_verif_syntax(&s))
		return (1);
	if (ft_atoui(s + 10) == 1)
	{
		data->me = 'O';
		data->ad = 'X';
	}
	else if (ft_atoui(s + 10) == 2)
	{
		data->me = 'X';
		data->ad = 'O';
	}
	else
	{
		ft_memdel((void **)&s);
		return (1);
	}
	ft_memdel((void **)&s);
	return (0);
}
