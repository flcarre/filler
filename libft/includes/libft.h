/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:44:47 by lutsiara          #+#    #+#             */
/*   Updated: 2019/02/27 15:40:45 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define PARTA LDBL_MANT_DIG + 28) / 29
# define PARTB (LDBL_MAX_EXP + LDBL_MANT_DIG + 28 + 8
# define SIZE_LD_TX (PARTA + 1 + PARTB) / 9

char				*ft_ull(unsigned long long x, char *s);
int					ft_signbit(double *x, long double *lx);
int					ft_isnan(long double x);
int					ft_isinf(long double x);
int					ft_dclassify(double x);
long double			ft_ldmod(long double x, long double mod);
double				ft_dmod(double x, double mod);
double				ft_dfrexp(double x, int *p);
long double			ft_ldfrexp(long double x, int *p);
double				ft_dexp(double x, int e);
long double			ft_ldexp(long double x, int e);
unsigned int		ft_ld_ldiglen(long double n, long double base);
void				*ft_memset(void *b, int c, unsigned long len);
void				ft_bzero(void *s, unsigned long n);
void				*ft_memcpy(void *dst, const void *src, unsigned long n);
void				*ft_memccpy(void *dst, const void *src, int c, \
					unsigned long n);
void				*ft_memmove(void *dst, const void *src, unsigned long len);
void				*ft_memchr(const void *s, int c, unsigned long n);
int					ft_memcmp(const void *s1, const void *s2, unsigned long n);
void				*ft_memalloc(unsigned long size);
void				ft_memdel(void **ap);
unsigned long		ft_strlen(const char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, unsigned long n);
int					ft_atoi(const char *str);
unsigned int		ft_atoui(const char *str);
unsigned int		ft_digitlen(long long n, int base);
unsigned int		ft_udigitlen(unsigned long long n, unsigned int base);
long				ft_iputchar(char c);
long				ft_iputxchar(char c, unsigned long x);
long				ft_iputstr(char const *s);
long				ft_iputnstr(char const *s, unsigned long n);
long				ft_iputwchar(int wc);
long				ft_iputwstr(int *ws);
unsigned long		ft_wcharlen(int wc);
long				ft_iputnwstr(int *ws, unsigned long n);
long				ft_iputnbr_base(long long n, char *base);
long				ft_iputunbr_base(unsigned long long n, char *base);
int					ft_isdigit(int c);
int					ft_isspace(int c);
double				ft_dabs(double x);
long double			ft_ldabs(long double x);
unsigned long		ft_wstrlen(const int *ws);

#endif
