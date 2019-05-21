/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 13:24:09 by flcarre           #+#    #+#             */
/*   Updated: 2019/05/21 17:32:10 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static int		ft_cut_n(char **line, char **buffer)
{
	char			*tmp;

	if ((tmp = ft_strrchr((const char *)*buffer, (int)'\n')))
		*tmp = '\0';
	*line = *buffer;
	return (1);
}

static int		ft_del(int ret, char **buffer)
{
	ft_memdel((void **)&(*buffer));
	return (ret);
}

int				gnl(const int fd, char **line)
{
	char			*tmp;
	char			*buffer;
	char			buff[2];
	long			ret;

	if (fd < 0 || !line)
		return (-1);
	ft_bzero((void *)buff, 2);
	buffer = (void *)0;
	while ((ret = read(fd, buff, 1)) > 0)
	{
		buff[ret] = '\0';
		tmp = buffer;
		buffer = ft_strjoin((char const *)buffer, (char const *)buff);
		ft_memdel((void **)&tmp);
		if (!buffer)
			return (-1);
		if (ft_strrchr((const char *)buffer, (int)'\n'))
			return (ft_cut_n(line, &buffer));
	}
	if (ret >= 0 && buffer)
		return (ft_cut_n(line, &buffer));
	return ((ret < 0) ? ft_del(ret, &buffer) : 0);
}
