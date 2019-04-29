/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 14:26:43 by flcarre           #+#    #+#             */
/*   Updated: 2019/04/29 18:55:42 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, unsigned long n)
{
	if (!s1 || !s2)
		return (0);
	return ((!ft_strncmp(s1, s2, n)) ? 1 : 0);
}
