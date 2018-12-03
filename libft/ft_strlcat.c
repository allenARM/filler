/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 19:14:10 by amelikia          #+#    #+#             */
/*   Updated: 2018/10/11 16:02:15 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst,
		const char *restrict src, size_t dstsize)
{
	size_t		i;
	size_t		dstlength;
	size_t		srclength;
	char		*str;

	str = (char*)src;
	i = 0;
	dstlength = ft_strlen(dst);
	srclength = ft_strlen(str);
	if (dstsize <= dstlength)
		return (srclength + dstsize);
	while ((dst[i] != '\0') && i < (dstsize - 1))
		i++;
	while (*src && i < (dstsize - 1))
	{
		dst[i] = *src;
		i++;
		src++;
	}
	dst[i] = '\0';
	return (dstlength + srclength);
}
