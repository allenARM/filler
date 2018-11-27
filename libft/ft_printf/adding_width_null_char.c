/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adding_width_null_char.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 23:18:44 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/01 12:01:24 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*adding_width_null_char(t_flags_ft_printf *flags, char *answer, \
		int *length, char **str)
{
	char	*width;

	*length += ft_strlen(*str);
	write(1, *str, ft_strlen(*str));
	*str = ft_update(*str, ft_strnew(1));
	if (flags->width <= 1)
	{
		ft_putchar('\0');
		return (answer);
	}
	width = ft_bchar(flags->width - 1, ' ');
	*length += ft_strlen(width);
	if (flags->right_padding == 0)
	{
		write(1, width, ft_strlen(width));
		ft_putchar('\0');
	}
	else
	{
		ft_putchar('\0');
		write(1, width, ft_strlen(width));
	}
	free(width);
	return (answer);
}
