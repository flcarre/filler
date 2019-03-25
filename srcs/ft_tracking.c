static void	ft_posinit(t_pos *p)
{
	p->d = -1;
	p->x = 0;
	p->y = 0;
	p->i = 0;
	p->j = 0;
}

int			ft_tracking(t_data *data)
{
	t_pos	p;

	ft_posinit(&p);
	while (p.i + data->p.y - 1 < data->m.y)
	{
		while (p.j + data->p.x - 1 < data->m.x)
		{
			if (ft_isok(data, &p))
			{
				if (p.d == -1 || ft_dist(data, &p) < p.d)
				{
					p.x = p.i;
					p.y = p.j;
					p.d = ft_dist(data, &p);
				}
			}
			p.j++;
		}
		p.j = 0;
		p.i++;
	}
	data->px = p.x;
	data->py = p.y;
}