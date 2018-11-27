/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 20:30:43 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/01 14:21:55 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_star_width(int *star_width, va_list *arg, \
		t_flags_ft_printf *flags)
{
	int width;

	*star_width = 1;
	width = va_arg(*arg, int);
	if (width < 0)
	{
		width = -width;
		flags->right_padding = 1;
	}
	flags->width = width;
}

char		*handling_width(char **format, t_flags_ft_printf *flags, \
		va_list *arg)
{
	int		star_width;

	star_width = 0;
	while (**format == '*' || ft_isdigit(**format))
	{
		if ((star_width == 1 && ft_isdigit(**format)) || \
			(star_width != 0 && **format == '*'))
			return (NULL);
		if (**format == '*')
			ft_star_width(&star_width, arg, flags);
		if (ft_isdigit(**format))
		{
			star_width = -1;
			flags->width = flags->width * 10 + **format - 48;
		}
		(*format)++;
	}
	return (*format);
}
