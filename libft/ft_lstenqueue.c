/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstenqueue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:43:40 by flcarre           #+#    #+#             */
/*   Updated: 2019/04/29 18:53:31 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstenqueue(t_list **list, t_list *elem)
{
	t_list		*i;

	if (!elem)
		return ;
	if (!(*list))
	{
		(*list) = elem;
		return ;
	}
	i = (*list);
	while (i->next)
		i = i->next;
	i->next = elem;
}
