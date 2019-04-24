/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delcontent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:37:13 by lutsiara          #+#    #+#             */
/*   Updated: 2019/04/24 15:44:35 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_delcontent(void *content, unsigned long content_size)
{
	if (!content)
		return ;
	ft_bzero(content, content_size);
	ft_memdel(&content);
}
