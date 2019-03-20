#include "filler.h"

void	ft_free(t_data *data)
{
	ft_strtabdel(&data->m.p);
	ft_strtabdel(&data->p.p);
}
