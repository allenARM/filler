/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 14:39:47 by amelikia          #+#    #+#             */
/*   Updated: 2018/10/19 14:48:50 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ncounter1(int i, va_list arg, const char *s)
{
	char	*counter;
	int		n1;

	n1 = 0;
	counter = "";
	if (s[i] == 'd' || s[i] == 'i')
	{
		counter = ft_itoa_base(va_arg(arg, int), 10);
		ft_putstr(counter);
		n1 += ft_strlen(counter);
	}
	if (s[i] == 'p')
	{
		ft_putstr("0x");
		counter = ft_itoa_base(va_arg(arg, unsigned long long), 16);
		ft_putstr(counter);
		n1 += 2 + ft_strlen(counter);
	}
	return (n1);
}

static int	ft_ncounter2(int i, va_list arg, const char *s)
{
	char	*counter;
	int		n1;

	n1 = 0;
	counter = "";
	if (s[i] == 'o')
	{
		counter = ft_itoa_base(va_arg(arg, unsigned int), 8);
		ft_putstr(counter);
		n1 += ft_strlen(counter);
	}
	if (s[i] == 'u')
	{
		counter = ft_itoa_base(va_arg(arg, unsigned int), 10);
		ft_putstr(counter);
		n1 += ft_strlen(counter);
	}
	if (s[i] == 'x')
	{
		counter = ft_itoa_base(va_arg(arg, unsigned int), 16);
		ft_putstr(counter);
		n1 += ft_strlen(counter);
	}
	return (n1);
}

static int	ft_ncounter3(int i, const char *s)
{
	int		n1;

	n1 = 0;
	if (s[i] == '%')
	{
		ft_putchar('%');
		n1++;
	}
	return (n1);
}

static int	ft_ncounter(int i, va_list arg, const char *s)
{
	char	*counter;
	int		n1;

	n1 = 0;
	counter = "";
	if (s[i] == 's')
	{
		counter = (va_arg(arg, char *));
		if (!counter)
			counter = "(null)";
		ft_putstr(counter);
		n1 += ft_strlen(counter);
	}
	if (s[i] == 'c')
	{
		ft_putchar(va_arg(arg, int));
		n1++;
	}
	n1 += ft_ncounter1(i, arg, s);
	n1 += ft_ncounter2(i, arg, s);
	n1 += ft_ncounter3(i, s);
	return (n1);
}

int			b_printf(const char *restrict s, ...)
{
	int		i;
	int		n;
	va_list	arg;

	va_start(arg, s);
	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '%' && s[i] != '\0')
		{
			ft_putchar(s[i]);
			n++;
			i++;
		}
		if (s[i] == '%' && s[i] != '\0')
		{
			i++;
			n += ft_ncounter(i, arg, s);
		}
		if (s[i] != '\0')
			i++;
	}
	va_end(arg);
	return (n);
}
