/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 16:09:24 by amelikia          #+#    #+#             */
/*   Updated: 2018/10/11 15:12:23 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = 0;
	dest = s1;
	while (dest[len])
		len++;
	while (s2[i])
	{
		dest[len + i] = s2[i];
		i++;
	}
	dest[len + i] = '\0';
	return (dest);
}
