#include "filler.h"

void	ft_printab_fd(char **p, int fd)
{
	int i;
	i = 0;
	while(p[i])
	{
		ft_putendl_fd(p[i], fd);
		i++;
	}
}