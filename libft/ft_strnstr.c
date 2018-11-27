/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 16:37:31 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/03 17:03:35 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*b;
	char	*l;
	char	*b_begin;

	l = (char*)little;
	if (*l == 0)
		return ((char*)big);
	b_begin = (char*)big;
	while ((*big) && ((size_t)(big - b_begin) < len))
	{
		b = (char*)big;
		if (*b == *little)
		{
			l = (char*)little;
			while ((*b == *l) && ((size_t)(b - b_begin) < len))
			{
				b++;
				l++;
				if (*l == 0)
					return ((char*)big);
			}
		}
		big++;
	}
	return (NULL);
}
