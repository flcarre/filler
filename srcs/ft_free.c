/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 03:46:07 by flcarre           #+#    #+#             */
/*   Updated: 2019/04/29 18:49:16 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_free(t_data *data)
{
	if (data->m.p)
		ft_strtabdel(&data->m.p);
	if (data->p.p)
		ft_strtabdel(&data->p.p);
	if (data->i.p)
		ft_strtabdel((char ***)&data->i.p);
	return (1);
}
