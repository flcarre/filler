/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:08:38 by flcarre           #+#    #+#             */
/*   Updated: 2019/04/29 18:55:48 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(const char *haystack, const char *needle, unsigned long len)
{
	unsigned long	i;
	unsigned long	j;

	if (!haystack || !len)
		return ((void *)0);
	if (!(*needle))
		return ((char *)haystack);
	j = 0;
	while (*haystack && j < len)
	{
		i = 0;
		while (*(needle + i) && *(haystack + i) == *(needle + i) && i + j < len)
			i++;
		if (!(*(needle + i)))
			return ((char *)haystack);
		haystack++;
		j++;
	}
	return ((void *)0);
}
