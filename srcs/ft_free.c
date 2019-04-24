/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 03:46:07 by lutsiara          #+#    #+#             */
/*   Updated: 2019/04/12 16:40:12 by lutsiara         ###   ########.fr       */
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
