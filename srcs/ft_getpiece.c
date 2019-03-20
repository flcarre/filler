#include "filler.h"

int	ft_getpiece(t_tab *p)
{
	char	*s;
	int		i;

	s = (void *)0;
	i = 0;
	get_next_line(0, &s);
	p->y = ft_atoui(ft_strchr(s, ' '));
	p->x = ft_atoui(ft_strchr(ft_strchr(s, ' ') + 1, ' '));
	p->p = ft_strtabnew(p->y, p->x);
	while(p->p[i])
	{
		ft_memdel((void **)&s);
		get_next_line(0, &s);
		ft_strcpy(p->p[i], s);
		i++;
	}
	ft_memdel((void **)&s);
	return (0);
}
