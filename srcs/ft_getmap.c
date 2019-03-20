#include "filler.h"

static int check_map(t_tab *m, unsigned int j)
{
	unsigned long	i;

	i = 0;
	while(m->p[j][i])
	{
		if (m->p[j][i] != '.' && m->p[j][i] != 'O' && m->p[j][i] != 'X')
		{
			ft_strtabdel(&m->p);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_getmap(t_tab *m)
{
	char				*s;
	unsigned int		i;

	s = (void *)0;
	i = 0;
	get_next_line(0, &s);
	m->y = ft_atoui(ft_strchr(s, ' '));
	m->x = ft_atoui(ft_strchr(ft_strchr(s, ' ') + 1, ' '));
	m->p = ft_strtabnew(m->y, m->x);
	ft_memdel((void **)&s);
	get_next_line(0, &s);
	while(m->p[i])
	{
		ft_memdel((void **)&s);
		get_next_line(0, &s);
		ft_strcpy(m->p[i], ft_strchr(s, ' ') + 1);
		if (check_map(m, i))
		{
			ft_memdel((void **)&s);
			return (1);
		}
		i++;
	}
	ft_memdel((void **)&s);
	return (0);
}
