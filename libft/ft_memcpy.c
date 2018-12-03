/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 14:58:22 by amelikia          #+#    #+#             */
/*   Updated: 2018/10/11 15:29:32 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char	*str;
	char	*src1;
	size_t	i;

	i = 0;
	str = dst;
	src1 = (char*)src;
	while (i < n)
	{
		str[i] = src1[i];
		i++;
	}
	return (str);
}
