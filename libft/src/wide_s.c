/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wide_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:38:16 by amelikia          #+#    #+#             */
/*   Updated: 2018/10/31 20:43:49 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int		ft_wstrlen(wchar_t *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int		idkwhy(wchar_t *str)
{
	int len;
	int counter;

	counter = 0;
	len = 0;
	while (str[len])
	{
		if (str[len] > 127)
			counter++;
		len++;
	}
	return (counter);
}

char	*ft_wstrdup(wchar_t *s1)
{
	int		i;
	char	*s2;

	s2 = (char *)malloc(sizeof(char) * (ft_wstrlen(s1) - idkwhy(s1)));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = (char)s1[i];
		if (s1[i] > 127)
			g_ohno++;
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
