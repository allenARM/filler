/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adding_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:55:10 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/31 16:04:50 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*assigning_width(t_flags_ft_printf *flags, char *str)
{
	char	fill;
	char	*width;

	fill = ' ';
	if (flags->zero_padding == 1 && flags->precision == 0 && \
			flags->conversion != 'p')
		fill = '0';
	if ((flags->conversion != 'x' || flags->conversion != 'X') && \
			flags->zero_padding == 1 && flags->hashtag == 1)
	{
		width = ft_bchar(flags->width - (int)ft_strlen(str) - 2, fill);
		width = ft_update(width, ft_strjoin("0x", width));
	}
	else
		width = ft_bchar(flags->width - (int)ft_strlen(str), fill);
	return (width);
}

char		*adding_width(t_flags_ft_printf *flags, char *str)
{
	char	*width;

	if (flags->width <= (int)ft_strlen(str))
		return (str);
	width = assigning_width(flags, str);
	if (flags->zero_padding == 1 && (str[0] == '+' || str[0] == '-' || \
				str[0] == ' '))
		str = ft_update(str, ft_strsub(str, 1, ft_strlen(str) - 1));
	if (flags->right_padding == 1)
		str = ft_update(str, ft_strjoin(str, width));
	if (flags->right_padding == 0)
		str = ft_update(str, ft_strjoin(width, str));
	if (flags->zero_padding == 1 && flags->minus == 1)
		str = ft_update(str, ft_strjoin("-", str));
	else if (flags->zero_padding == 1 && flags->plus == 1)
		str = ft_update(str, ft_strjoin("+", str));
	else if (flags->zero_padding == 1 && flags->space == 1)
		str = ft_update(str, ft_strjoin(" ", str));
	free(width);
	return (str);
}
