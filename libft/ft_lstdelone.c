/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:28:54 by flcarre           #+#    #+#             */
/*   Updated: 2019/04/29 18:53:18 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, unsigned long))
{
	if (!(*alst) || !del)
		return ;
	del((*alst)->content, (*alst)->content_size);
	ft_memdel((void **)&(*alst));
	*alst = (void *)0;
}
