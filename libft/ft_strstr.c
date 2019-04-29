/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:51:01 by flcarre           #+#    #+#             */
/*   Updated: 2019/04/29 18:55:56 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned long	i;

	if (!haystack)
		return ((void *)0);
	if (!needle || !(*needle))
		return ((char *)haystack);
	while (*haystack)
	{
		i = 0;
		while (*(needle + i) && *(haystack + i) == *(needle + i))
			i++;
		if (!(*(needle + i)))
			return ((char *)haystack);
		haystack++;
	}
	return ((void *)0);
}
