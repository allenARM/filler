/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 10:49:08 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/15 10:59:11 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strsch(char *str, char *to_find)
{
	int		i;
	int		j;
	int		ret;

	if (str == NULL)
		return (-1);
	if (to_find == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] == to_find[j] && str)
		{
			ret = i;
			++i;
			++j;
			if (to_find[j] == '\0')
				return (ret);
		}
		if (str[i] != '\0')
			++i;
	}
	return (-1);
}
