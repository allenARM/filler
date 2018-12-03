/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 16:15:51 by amelikia          #+#    #+#             */
/*   Updated: 2018/10/11 15:58:15 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	size_t	i;
	int		s;

	i = 0;
	s = 0;
	while (s1[s])
		s++;
	while (i < n && s2[i])
	{
		s1[s] = s2[i];
		++s;
		++i;
	}
	s1[s] = '\0';
	return (s1);
}
