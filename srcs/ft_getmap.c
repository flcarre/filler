#include "filler.h"

int	ft_getmap(t_tab *m)
{
	char	*s;
	int		i;

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
		i++;
	}
	ft_memdel((void **)&s);
	return (0);
}
