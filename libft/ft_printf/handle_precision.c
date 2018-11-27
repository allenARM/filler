/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 20:30:38 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/01 14:22:10 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_star_precision(int *star_precision, va_list *arg, \
								t_flags_ft_printf *flags)
{
	int		precision;

	*star_precision = -1;
	precision = va_arg(*arg, int);
	flags->precision = precision;
}

char		*handling_precision(char **format, t_flags_ft_printf *flags, \
								va_list *arg)
{
	int		star_precision;

	star_precision = 0;
	if (**format == '.')
		while (**format == '.' || **format == '*' || ft_isdigit(**format))
		{
			flags->precision_exist = 1;
			if (star_precision == 1 && ft_isdigit(**format))
				return (NULL);
			if (star_precision != 0 && **format == '*')
				return (NULL);
			if (**format == '*')
				ft_star_precision(&star_precision, arg, flags);
			if (ft_isdigit(**format))
			{
				star_precision = -1;
				flags->precision = flags->precision * 10 + **format - 48;
			}
			(*format)++;
		}
	return (*format);
}
