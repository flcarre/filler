/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:57:49 by lutsiara          #+#    #+#             */
/*   Updated: 2019/03/20 01:25:56 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct			s_tab
{
	char				**p;
	unsigned int		x;
	unsigned int		y;
}						t_tab;

typedef struct			s_data
{
	t_tab				m;
	t_tab				p;
	char				me;
	char				ad;
	unsigned int		px;
	unsigned int		py;
}						t_data;

void					ft_init(t_data *data);

#endif
