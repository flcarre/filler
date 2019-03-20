/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:39:24 by lutsiara          #+#    #+#             */
/*   Updated: 2019/03/13 16:26:19 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long	ft_countword(char const *s, char c)
{
	unsigned long	word;

	word = 0;
	if (!s)
		return (word);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			word++;
		while (*s && *s != c)
			s++;
	}
	return (word);
}
