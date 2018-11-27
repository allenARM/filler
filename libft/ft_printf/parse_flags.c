/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 19:50:12 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/31 20:53:33 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			parse_flags(char **format, t_flags_ft_printf *flags, va_list *arg)
{
	if ((handling_flags(format, flags)) == NULL)
		return (-1);
	if ((handling_width(format, flags, arg)) == NULL)
		return (-1);
	if ((handling_precision(format, flags, arg)) == NULL)
		return (-1);
	if ((handling_format(format, flags)) == NULL)
		return (-1);
	flags->conversion = (**format);
	if (!ft_strcmp(flags->format, "l") && (**format) == 'c')
		flags->conversion = 'C';
	if (!ft_strcmp(flags->format, "l") && (**format) == 's')
		flags->conversion = 'S';
	return (1);
}
