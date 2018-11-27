/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 20:30:23 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/31 20:30:24 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*handling_flags(char **format, t_flags_ft_printf *flags)
{
	while (**format == '#' || **format == ' ' || **format == '+' || \
			**format == '-' || **format == '0')
	{
		if (**format == '#')
			flags->hashtag = 1;
		if (**format == '-')
			flags->right_padding = 1;
		if (**format == ' ')
			flags->space = 1;
		if (**format == '+')
			flags->plus = 1;
		if (**format == '0')
			flags->zero_padding = 1;
		if (flags->right_padding == 1)
			flags->zero_padding = 0;
		(*format)++;
	}
	return (*format);
}
