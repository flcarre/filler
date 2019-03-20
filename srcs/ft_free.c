/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 03:46:07 by lutsiara          #+#    #+#             */
/*   Updated: 2019/03/20 04:40:44 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_free(t_data *data)
{
	ft_strtabdel(&data->m.p);
	ft_strtabdel(&data->p.p);
	ft_strtabdel((char ***)&data->i.p);
}
