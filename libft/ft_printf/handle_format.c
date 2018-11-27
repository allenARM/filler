/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 20:30:28 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/31 20:30:30 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*handling_format(char **format, t_flags_ft_printf *flags)
{
	flags->format = ft_strnew(1);
	if ((**format) == 'l')
		flags->format = ft_update(flags->format, ft_strdup("l"));
	if ((**format) == 'h')
		flags->format = ft_update(flags->format, ft_strdup("h"));
	if ((**format) == 'j')
		flags->format = ft_update(flags->format, ft_strdup("j"));
	if ((**format) == 'z')
		flags->format = ft_update(flags->format, ft_strdup("z"));
	if ((**format) == 'z' || (**format) == 'j' || (**format) == 'l' || \
		(**format) == 'h')
		(*format)++;
	if ((**format) == 'h' && !ft_strcmp(flags->format, "h"))
		flags->format = ft_update(flags->format, ft_strdup("hh"));
	if ((**format) == 'l' && !ft_strcmp(flags->format, "l"))
		flags->format = ft_update(flags->format, ft_strdup("ll"));
	if (!ft_strcmp(flags->format, "ll") || !ft_strcmp(flags->format, "hh"))
		(*format)++;
	return (*format);
}
