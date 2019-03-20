/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_udigitlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 18:35:45 by flcarre           #+#    #+#             */
/*   Updated: 2019/02/14 21:24:39 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_udigitlen(unsigned long long n, unsigned int base)
{
	unsigned int	len;

	if (base < 2)
		return (0);
	len = (!n) ? 1 : 0;
	while (n)
	{
		len++;
		n /= base;
	}
	return (len);
}
