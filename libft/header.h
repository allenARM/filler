/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 18:30:21 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/01 14:44:21 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <wchar.h>
# include "libft.h"

typedef struct	s_arg
{
	int		hashtag;
	int		right_pending;
	int		star_precision;
	int		star_width;
	int		minus;
	int		plus;
	int		zero_pending;
	int		space;
	int		width;
	int		precision;
	int		nonascii;
	int		null;
	char	*format;
	char	type;
}				t_arg;

char			*g_word;
int				g_ohno;

int				ft_printf(const char *restrict format, ...);
char			*type_define(va_list arg, t_arg *data);
char			*adding_precision_string(t_arg *data, char *str);
char			*adding_precision_number(t_arg *data, char *str);
void			parse_width(va_list arg, const char *s, int *i, t_arg *data);
void			parse_accuracy(va_list arg, const char *s, int *i, t_arg *data);
void			parse_type(const char *s, int *i, t_arg *data);
void			parse_data(const char *s, int *i, t_arg *data);
void			parse_format(const char *s, int *i, t_arg *data);
void			makezero(t_arg *data);
void			after_percentage_checker(va_list arg, const char *s, int *i);
char			*conversion_s_ws(va_list arg, t_arg *data);
char			*conversion_c_wc(va_list arg, t_arg *data);
char			*conversion_p(va_list arg);
char			*conversion_b(va_list arg, t_arg *data);
char			*conversion_u_cd_cu(va_list arg, t_arg *data);
char			*conversion_d_i(va_list arg, t_arg *data);
char			*conversion_x_cx(va_list arg, t_arg *data);
char			*conversion_o_co(va_list arg, t_arg *data);
char			*adding_minus(t_arg *data, char *str);
char			*adding_space(t_arg *data, char *str);
char			*adding_plus(t_arg *data, char *str);
char			*ft_wstrdup(wchar_t *s1);
char			*adding_width(t_arg *data, char *str);
char			*ft_itoa_base_unsigned(uintmax_t value, int base);
char			*ft_itoa_intmax(long long value);
char			*ft_itoa_unsigned(uintmax_t value);

#endif
