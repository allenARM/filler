/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 16:27:51 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/03 17:04:33 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int	i;
	int	z;
	int	find_size;

	i = 0;
	z = 0;
	find_size = 0;
	while (to_find[find_size] != '\0')
		find_size++;
	if (find_size == 0)
		return ((char *)str);
	while (str[i] != '\0')
	{
		while (to_find[z] == str[i + z])
		{
			if (z == find_size - 1)
				return ((char *)(str + i));
			z++;
		}
		z = 0;
		i++;
	}
	return (0);
}
