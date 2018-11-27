/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_wide_c.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 18:46:18 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/01 14:19:58 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*conversion_wide_c(va_list *arg, int *length, \
		t_flags_ft_printf *flags)
{
	wchar_t		tmp_chr;
	char		chr;
	char		*str;

	tmp_chr = va_arg(*arg, wint_t);
	chr = (char)tmp_chr;
	if (chr == '\0')
	{
		(*length)++;
		flags->null_char = 1;
		str = ft_strnew(1);
	}
	else
		str = ft_bchar(1, chr);
	return (str);
}
