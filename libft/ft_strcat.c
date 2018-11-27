/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 12:47:05 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/03 16:59:23 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int i;
	int s;

	i = 0;
	s = 0;
	while (dest[s])
		++s;
	while (src[i])
	{
		dest[s] = src[i];
		++s;
		++i;
	}
	dest[s] = '\0';
	return (dest);
}
