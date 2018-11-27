/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 19:42:21 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/01 14:19:08 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						final_print(const char *format, char *str)
{
	int					length;

	str = ft_update(str, ft_strjoin(str, format));
	write(1, str, ft_strlen(str));
	length = ft_strlen(str);
	free(str);
	return (length);
}

int						narrow_ft_printf(const char *format, va_list *arg, \
		char *str)
{
	t_flags_ft_printf	flags;
	char				*next;
	char				*tmp;
	static int			length;

	if (!length)
		length = 0;
	next = ft_strchr(format, '%');
	if (next == NULL)
		return (length + final_print(format, str));
	tmp = ft_strccrt(format, '%');
	str = ft_update(str, ft_strjoin(str, tmp));
	free(tmp);
	++next;
	ft_bzero(&flags, sizeof(t_flags_ft_printf));
	parse_flags(&next, &flags, arg);
	tmp = conversions(&flags, arg, &length, &str);
	str = ft_update(str, ft_strjoin(str, tmp));
	++next;
	free(tmp);
	free(flags.format);
	return (narrow_ft_printf(next, arg, str));
}

int						ft_printf(const char *format, ...)
{
	int					length;
	char				*str;
	va_list				arg;

	length = 0;
	str = ft_strnew(1);
	va_start(arg, format);
	length = narrow_ft_printf(format, &arg, str);
	va_end(arg);
	return (length);
}
