/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adding_precision_number.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:41:21 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/31 15:47:37 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*creating_precision_string(t_flags_ft_printf *flags, char *str)
{
	int		i;
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * flags->precision + 1);
	i = 0;
	while (i < (flags->precision - (int)ft_strlen(str)))
		tmp[i++] = '0';
	while (*str)
	{
		tmp[i++] = *str;
		++str;
	}
	tmp[i] = '\0';
	return (tmp);
}

char		*adding_precision_number(t_flags_ft_printf *flags, char *str)
{
	char	*tmp;

	tmp = ft_strnew(1);
	if (flags->conversion != 'd' && flags->conversion != 'i' && \
			flags->conversion != 'U' && flags->conversion != 'u' && \
			flags->conversion != 'D' && flags->conversion != 'X' && \
			flags->conversion != 'o' && flags->conversion != 'x' && \
			flags->conversion != 'O')
	{
		tmp = ft_update(tmp, ft_strdup(str));
		return (tmp);
	}
	if (!((flags->conversion == 'o' || flags->conversion == 'O') && \
				flags->hashtag == 1))
		if (flags->precision == 0 && !ft_strcmp(str, "0"))
			return (tmp);
	if (flags->precision <= (int)ft_strlen(str))
	{
		tmp = ft_update(tmp, ft_strdup(str));
		return (tmp);
	}
	tmp = ft_update(tmp, creating_precision_string(flags, str));
	return (tmp);
}
