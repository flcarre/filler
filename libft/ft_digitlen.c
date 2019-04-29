/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:21:08 by flcarre           #+#    #+#             */
/*   Updated: 2019/04/29 18:51:08 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_digitlen(int n, int base)
{
	unsigned int	len;

	if (base < 2)
		return (0);
	len = (!n) ? 1 : 0;
	len += (n < 0) ? 1 : 0;
	while (n)
	{
		len++;
		n /= base;
	}
	return (len);
}
