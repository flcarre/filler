/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whoami.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 03:47:28 by lutsiara          #+#    #+#             */
/*   Updated: 2019/03/20 03:47:30 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_whoami(t_data *data)
{
	char	*s;

	s = (void *)0;
	get_next_line(0, &s);
	if (s[10] == '1')
	{
		data->me = 'O';
		data->ad = 'X';
	}
	else if (s[10] == '2')
	{
		data->me = 'X';
		data->ad = 'O';
	}
	ft_memdel((void **)&s);
}
