/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 22:32:54 by amelikia          #+#    #+#             */
/*   Updated: 2018/10/31 16:16:52 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static char	*itoa_filler(char *tab, uintmax_t value, int base)
{
	uintmax_t			tmp;
	int					size;
	char				*str;

	size = 0;
	tmp = value;
	while (tmp /= base)
		size++;
	size = size + 1;
	str = (char *)malloc(sizeof(char) * size + 1);
	str[size] = '\0';
	while (size > 0)
	{
		str[size - 1] = tab[value % base];
		size--;
		value = value / base;
	}
	return (str);
}

char		*ft_itoa_base_unsigned(uintmax_t value, int base)
{
	char				*str;
	char				*tab;

	tab = "0123456789abcdef";
	str = itoa_filler(tab, value, base);
	return (str);
}
