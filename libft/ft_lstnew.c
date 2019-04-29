/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:03:39 by flcarre           #+#    #+#             */
/*   Updated: 2019/04/29 18:53:53 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, unsigned long content_size)
{
	t_list		*new;

	if (!(new = (t_list *)ft_memalloc(sizeof(t_list))))
		return ((void *)0);
	if (!content)
	{
		new->content = (void *)0;
		new->content_size = 0;
		new->next = (void *)0;
		return (new);
	}
	new->content = ft_memcpy(ft_memalloc(content_size), content, content_size);
	if (!(new->content))
	{
		ft_memdel((void **)&new);
		return ((void *)0);
	}
	new->content_size = content_size;
	new->next = (void *)0;
	return (new);
}
