/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 18:07:32 by lutsiara          #+#    #+#             */
/*   Updated: 2019/03/07 07:18:31 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/includes/libft.h"
# include <stdarg.h>
# include <wchar.h>

typedef struct				s_id
{
	unsigned char			fm;
	unsigned int			w;
	unsigned int			p[2];
	char					lm[3];
	char					id[10];
}							t_id;

int							ft_printf(const char *format, ...);
int							ft_converter(char **fmt, va_list args, int *r);
void						ft_parse(t_id *e, char **f, va_list args);
int							ft_idisnull(t_id *e);
int							ft_isid(char c);
int							ft_isfm(char c);
long						ft_iputldnbr(long double x, t_id *e);
long						ft_simuldnbr(long double x, t_id *e);
int							ft_printcolor(t_id *e);
void						ft_dorounding(unsigned int *p[4], t_id *e);
int							ft_print0(t_id *e, va_list args);
int							ft_print1(t_id *e, va_list args);
int							ft_print2(t_id *e, va_list args);
int							ft_print3(t_id *e, va_list args);
int							ft_print4(t_id *e, va_list args);
int							ft_print5(t_id *e, va_list args);
int							ft_print6(t_id *e, va_list args);
int							ft_print7(t_id *e, va_list args);
int							ft_print8(t_id *e, va_list args);
int							ft_print9(t_id *e, va_list args);
int							ft_print10(t_id *e, va_list args);
int							ft_print11(t_id *e, va_list args);
int							ft_print12(t_id *e, va_list args);
int							ft_print13(t_id *e, va_list args);
int							ft_print14(t_id *e, va_list args);
int							ft_print15(t_id *e, va_list args);
int							ft_print16(t_id *e, va_list args);
int							ft_print17(t_id *e, va_list args);
int							ft_wprocess0(t_id *e, long long x);
int							ft_wprocess1(t_id *e, char *s);
int							ft_wprocess2(t_id *e, wchar_t *ws);
int							ft_wprocess3(t_id *e, unsigned long long x);
int							ft_wprocess4(t_id *e, long double x);
int							ft_pprocess0(t_id *e, long long x);
int							ft_pprocess1(t_id *e, char *s);
int							ft_pprocess2(t_id *e, wchar_t *ws);
int							ft_pprocess3(t_id *e, unsigned long long x);
int							ft_pprocess4(t_id *e, long double x);
void						ft_wcalc0(t_id *e, unsigned long long x);
void						ft_wcalc1(t_id *e, long double x);

#endif
