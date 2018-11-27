/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 10:15:59 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/01 14:21:37 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include "../libft.h"

typedef struct	s_flags_ft_printf
{
	int			null_char;
	int			hashtag;
	int			right_padding;
	int			minus;
	int			plus;
	int			zero_padding;
	int			width;
	int			precision;
	int			precision_exist;
	int			space;
	char		conversion;
	char		*format;
}				t_flags_ft_printf;
int				parse_flags(char **format, t_flags_ft_printf *flags, \
			va_list *arg);
char			*handling_flags(char **format, t_flags_ft_printf *flags);
char			*handling_format(char **format, t_flags_ft_printf *flags);
char			*handling_precision(char **format, t_flags_ft_printf *flags, \
			va_list *arg);
char			*handling_width(char **format, t_flags_ft_printf *flags, \
			va_list *arg);
int				regular_character_string(char **next, \
			t_flags_ft_printf *flags, va_list *arg);
int				wide_character_string(char **next, t_flags_ft_printf *flags, \
			va_list *arg);
char			*conversions(t_flags_ft_printf *flags, va_list *arg, \
			int *length, char **str);
char			*conversion_c(va_list *arg, int *length, \
			t_flags_ft_printf *flags);
char			*conversion_wide_c(va_list *arg, int *length, \
			t_flags_ft_printf *flags);
char			*conversion_wide_s(va_list *arg);
char			*conversion_s(va_list *arg);
char			*conversion_b(va_list *arg, t_flags_ft_printf *flags);
char			*conversion_p(va_list *arg);
char			*conversion_d_i(va_list *arg, t_flags_ft_printf *flags);
char			*conversion_o_cap_o(va_list *arg, t_flags_ft_printf *flags);
char			*conversion_x_cap_x(va_list *arg, t_flags_ft_printf *flags);
char			*conversion_u_cap_d_cap_u(va_list *arg, \
			t_flags_ft_printf *flags);
char			*adding_width(t_flags_ft_printf *flags, char *str);
int				adding_width_wide(t_flags_ft_printf *flags, int length_str);
char			*adding_width_null_char(t_flags_ft_printf *flags, \
			char *answer, int *length, char **str);
char			*adding_plus(t_flags_ft_printf *flags, char *str);
char			*adding_space(t_flags_ft_printf *flags, char *str);
char			*adding_minus(t_flags_ft_printf *flags, char *str);
char			*adding_precision_string(t_flags_ft_printf *flags, char *str);
char			*adding_precision_number(t_flags_ft_printf *flags, char *str);
int				ft_printf(const char *format, ...);
int				printing_string_wide(wchar_t *str);
char			*ft_itoa_intmax(long long value);
char			*ft_itoa_unsigned(uintmax_t value);
char			*ft_itoa_base_unsigned(uintmax_t value, int base);

#endif
