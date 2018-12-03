/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_intmax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 22:33:32 by amelikia          #+#    #+#             */
/*   Updated: 2018/10/31 16:04:00 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static char		*itoa_filler(char *tab, long long value, int flag)
{
	long long	tmp;
	int			size;
	char		*str;

	size = 0;
	tmp = ft_abs(value);
	while (tmp /= 10)
		size++;
	size = size + flag + 1;
	str = (char *)malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (NULL);
	str[size] = '\0';
	if (flag == 1)
		str[0] = '-';
	while (size > flag)
	{
		str[size - 1] = tab[ft_abs(value % 10)];
		size--;
		value = value / 10;
	}
	return (str);
}

char			*ft_itoa_intmax(long long value)
{
	char		*str;
	char		*tab;
	int			flag;

	flag = 0;
	tab = "0123456789abcdef";
	if (value < 0)
		flag = 1;
	str = itoa_filler(tab, value, flag);
	return (str);
}
