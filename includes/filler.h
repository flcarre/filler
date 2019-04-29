/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:57:49 by flcarre           #+#    #+#             */
/*   Updated: 2019/04/29 18:50:28 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"

typedef struct			s_tab
{
	char				**p;
	unsigned int		x;
	unsigned int		y;
}						t_tab;

typedef struct			s_pos
{
	int					d;
	int					f;
	unsigned int		x;
	unsigned int		y;
	unsigned int		i;
	unsigned int		j;
	unsigned int		sx;
	unsigned int		sy;
}						t_pos;

typedef struct			s_tac
{
	int					**p;
	unsigned int		x;
	unsigned int		y;
}						t_tac;

typedef struct			s_data
{
	t_tab				m;
	t_tab				p;
	t_tac				i;
	char				me;
	char				ad;
	int					px;
	int					py;
}						t_data;

void					ft_init(t_data *data);
int						ft_whoami(t_data *data);
int						ft_getmap(t_tab *m);
int						ft_alloccalc(t_data *data);
int						ft_getpiece(t_tab *p);
int						ft_fight(t_data *data);
void					ft_calcmap(t_data *data);
int						ft_tracking(t_data *data);
int						ft_isok(t_data *data, t_pos *p);
int						ft_dist(t_data *data, t_pos *p);
int						ft_updatemap(t_tab *m);
int						ft_free(t_data *data);
void					ft_resetmap(t_tac *i);

#endif
