/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 13:51:53 by amelikia          #+#    #+#             */
/*   Updated: 2018/10/25 13:43:51 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*itoa_filler(char *tab, long long value, int base, int flag)
{
	unsigned long long	tmp;
	int					size;
	char				*str;

	size = 0;
	tmp = ft_abs(value);
	while (tmp /= base)
		size++;
	size = size + flag + 1;
	if ((str = (char *)malloc(sizeof(char) * size + 1)) == NULL)
		return (NULL);
	str[size] = '\0';
	if (flag == 1)
		str[0] = '-';
	while (size > flag)
	{
		str[size - 1] = tab[ft_abs(value % base)];
		size--;
		value = value / base;
	}
	return (str);
}

char		*ft_itoa_base_big(long long value, int base)
{
	char	*str;
	char	*tab;
	int		flag;

	flag = 0;
	tab = "0123456789ABCDEF";
	if (base < 2 || base > 16)
		return (str = "ERROR");
	if (value < 0 && base == 10)
		flag = 1;
	str = itoa_filler(tab, value, base, flag);
	return (str);
}

char		*ft_itoa_base(long long value, int base)
{
	char	*str;
	char	*tab;
	int		flag;

	flag = 0;
	tab = "0123456789abcdef";
	if (base < 2 || base > 16)
		return (str = "ERROR");
	if (value < 0 && base == 10)
		flag = 1;
	str = itoa_filler(tab, value, base, flag);
	return (str);
}
