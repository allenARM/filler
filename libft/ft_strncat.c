/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 14:03:34 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/03 17:02:48 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	size_t	i;
	int		s;

	i = 0;
	s = 0;
	while (dest[s])
		++s;
	while (i < nb && src[i])
	{
		dest[s] = src[i];
		++s;
		++i;
	}
	dest[s] = '\0';
	return (dest);
}
