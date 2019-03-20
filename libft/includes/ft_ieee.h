/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ieee.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 20:17:34 by lutsiara          #+#    #+#             */
/*   Updated: 2019/01/22 23:14:51 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IEEE_H
# define FT_IEEE_H

# define D_EXPB 11
# define D_FHB 20
# define D_FLB 32
# define D_FB (D_FHB + D_FLB)

# define LD_EXPB 15
# define LD_FHB 32
# define LD_FLB 32
# define LD_PLB 32
# define LD_PHB 16
# define LD_FB (LD_FHB + LD_FLB + LD_PLB + LD_PHB)

typedef struct		s_ieee_d
{
	unsigned int	fl:D_FLB;
	unsigned int	fh:D_FHB;
	unsigned int	e:D_EXPB;
	unsigned int	s:1;
}					t_ieee_d;

typedef struct		s_ieee_ld
{
	unsigned int	fl:LD_FLB;
	unsigned int	fh:LD_FHB;
	unsigned int	e:LD_EXPB;
	unsigned int	s:1;
	unsigned int	ph:LD_PHB;
	unsigned int	pl:LD_PLB;
}					t_ieee_ld;

typedef union		u_ieee_d
{
	double			d;
	t_ieee_d		sd;
}					t_u_ieee_d;

typedef union		u_ieee_ld
{
	long double		ld;
	t_ieee_ld		sld;
}					t_u_ieee_ld;

# define D_EXP_INFNAN 2047
# define LD_EXP_INFNAN 32767

# define D_QUIETNAN (1 << 19)
# define LD_QUIETNAN (1 << 15)

# define D_EXP_BIAS 1023
# define LD_EXP_BIAS 16383

#endif
