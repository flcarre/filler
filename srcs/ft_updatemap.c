#include "filler.h"

void	ft_updatemap(t_tab *m)
{
	char	*s;
	int		i;

	s = (void *)0;
	i = 0;
	get_next_line(0, &s);
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