/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 16:07:01 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/31 22:24:43 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*conversion_c(va_list *arg, int *length, t_flags_ft_printf *flags)
{
	char	*str;
	int		tmp;

	tmp = va_arg(*arg, int);
	if (tmp == '\0')
	{
		(*length)++;
		flags->null_char = 1;
		str = ft_strnew(1);
	}
	else
		str = ft_bchar(1, (char)tmp);
	return (str);
}
