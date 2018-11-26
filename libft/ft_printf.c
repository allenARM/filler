/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 21:29:31 by amelikia          #+#    #+#             */
/*   Updated: 2018/10/31 22:36:13 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	because_str(const char *s, int i)
{
	char	*str;

	str = ft_makestr(s[i]);
	g_word = ft_update(g_word, ft_strjoin(g_word, str));
	free(str);
}

void	start_printf(va_list arg, const char *s)
{
	int		i;

	i = 0;
	g_word = ft_strnew(1);
	while (s[i] != '\0')
	{
		while (s[i] != '%' && s[i] != '\0')
		{
			because_str(s, i);
			i++;
		}
		if (s[i] == '%' && s[i] != '\0')
		{
			if (s[i + 1] != '\0')
				i++;
			after_percentage_checker(arg, s, &i);
		}
	}
}

int		ft_printf(const char *restrict format, ...)
{
	int		number_of_char;
	va_list	arg;

	g_ohno = 0;
	va_start(arg, format);
	start_printf(arg, format);
	number_of_char = ft_strlen(g_word);
	write(1, g_word, number_of_char);
	va_end(arg);
	if (g_word != NULL)
		ft_strdel(&g_word);
	return (number_of_char + g_ohno);
}
