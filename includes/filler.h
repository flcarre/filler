/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flxw <flxw@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:57:49 by lutsiara          #+#    #+#             */
/*   Updated: 2019/03/20 02:52:31 by flxw             ###   ########.fr       */
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
void					ft_whoami(t_data *data);
int						ft_getmap(t_tab *m);
int						ft_getpiece(t_tab *p);
void					ft_printab_fd(char **p, int fd);

#endif
