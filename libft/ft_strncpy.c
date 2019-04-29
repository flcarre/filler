/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:42:30 by flcarre           #+#    #+#             */
/*   Updated: 2019/04/29 18:55:39 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dst, const char *src, unsigned long len)
{
	unsigned long	i;

	if (!len)
		return (dst);
	i = 0;
	while (*src && i < len)
		*(dst + (i++)) = *(src++);
	while (i < len)
		*(dst + (i++)) = '\0';
	return (dst);
}
