/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 13:03:56 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/03 17:04:21 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		find_wd_count(const char *s, char d)
{
	int			position;
	int			nb;

	position = 0;
	nb = 0;
	while (*s != '\0')
	{
		if (*s != d && position == 0)
		{
			position = 1;
			nb++;
		}
		if (*s == d && position == 1)
			position = 0;
		s++;
	}
	return (nb);
}

static int		find_wd_len(const char *s, char d)
{
	int			len;

	len = 0;
	while (*s != '\0' && *s != d)
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**str;
	int			wd;
	int			i;

	i = 0;
	if (!s)
		return (0);
	wd = find_wd_count(s, c);
	str = (char**)malloc(sizeof(*str) * (find_wd_count(s, c) + 1));
	if (str == NULL)
		return (NULL);
	while (wd > 0)
	{
		while (*s == c && *s != '\0')
			s++;
		str[i] = ft_strsub(s, 0, find_wd_len(s, c));
		if (str[i] == NULL)
			return (NULL);
		s = s + find_wd_len(s, c);
		i++;
		wd--;
	}
	str[i] = NULL;
	return (str);
}
