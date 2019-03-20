/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 13:24:09 by lutsiara          #+#    #+#             */
/*   Updated: 2018/11/28 20:14:05 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static t_list	*ft_select(int fd, t_list *fd_buff)
{
	t_list			*p;
	int				*f;

	if (!fd_buff)
		return ((void *)0);
	while (fd_buff)
	{
		p = (t_list *)fd_buff->content;
		f = (int *)(p->content);
		if (fd == *f)
			return (p);
		fd_buff = fd_buff->next;
	}
	return ((void *)0);
}

static t_list	*ft_add(int fd, t_list **fd_buff)
{
	t_list			*tmp;
	t_list			*f;

	tmp = (void *)0;
	if (!(tmp = ft_lstnew((void const *)&fd, sizeof(int))))
		return ((void *)0);
	ft_lstenqueue(&tmp, ft_lstnew((void const *)"\0", 1));
	if (!(tmp->next))
	{
		ft_lstdel(&tmp, &ft_delcontent);
		return ((void *)0);
	}
	if (!(f = ft_lstnew((void const *)(void *)0, 0)))
	{
		ft_lstdel(&tmp, &ft_delcontent);
		return ((void *)0);
	}
	f->content = (void *)tmp;
	f->content_size = sizeof(t_list) * 2 + sizeof(int) + 1;
	ft_lstenqueue(fd_buff, f);
	f = *fd_buff;
	while (f->next)
		f = f->next;
	return ((t_list *)f->content);
}

static int		ft_cpy_n_cut(char **line, t_list **buff)
{
	char			*s;
	unsigned long	i;

	i = 0;
	s = (char *)(*buff)->content;
	while (*(s + i) && *(s + i) != '\n')
		i++;
	if (!(*line = ft_strsub((char const *)s, 0, i)))
		return (-1);
	i += (*(s + i) == '\n') ? 1 : 0;
	(*buff)->content = (void *)ft_strdup(s + i);
	free(s);
	s = (char *)(*buff)->content;
	if (!s)
		return (-1);
	(*buff)->content_size = ft_strlen((const char *)s) + 1;
	return (1);
}

static int		ft_fddel(t_list **fd_buff, t_list **p)
{
	t_list		*f;
	t_list		*i;

	f = (*fd_buff);
	while (f->content != (void *)(*p))
	{
		i = f;
		f = f->next;
	}
	if (f == (*fd_buff))
	{
		i = f->next;
		ft_lstdel(p, &ft_delcontent);
		(*fd_buff)->content_size = 0;
		ft_lstdelone(fd_buff, &ft_delcontent);
		*fd_buff = i;
	}
	else
	{
		ft_lstdel(p, &ft_delcontent);
		f->content_size = 0;
		i->next = f->next;
		ft_lstdelone(&f, &ft_delcontent);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*fd_buff = (void *)0;
	t_list			*p;
	char			*s;
	char			b[ft_abs(BUFF_SIZE) + 1];
	long			r;

	if (fd < 0 || !line || !(p = ft_select(fd, fd_buff)))
		if (fd < 0 || !line || !(p = ft_add(fd, &fd_buff)))
			return (-1);
	while ((r = read(fd, b, BUFF_SIZE)) > 0)
	{
		b[r] = '\0';
		s = (char *)(p->next->content);
		p->next->content = (void *)ft_strjoin((char const *)s, (char const *)b);
		free(s);
		p->next->content_size = 0;
		if (!(p->next->content))
			return (-1);
		p->next->content_size = ft_strlen((const char *)p->next->content) + 1;
		if (ft_strchr((const char *)p->next->content, (int)'\n'))
			return (ft_cpy_n_cut(line, &(p->next)));
	}
	if (r >= 0 && ft_strlen((const char *)p->next->content))
		return (ft_cpy_n_cut(line, &(p->next)));
	return ((r < 0) ? -1 : ft_fddel(&fd_buff, &p));
}
