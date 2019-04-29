/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:37:35 by flcarre           #+#    #+#             */
/*   Updated: 2019/04/29 18:55:34 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(const char *s1, const char *s2, unsigned long n)
{
	if (!n)
		return (0);
	while (--n && *s1 && *s2)
	{
		if ((unsigned char)(*s1) != (unsigned char)(*s2))
			return ((int)((unsigned char)(*s1) - (unsigned char)(*s2)));
		s1++;
		s2++;
	}
	return ((int)((unsigned char)(*s1) - (unsigned char)(*s2)));
}
