/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 22:29:15 by amelikia          #+#    #+#             */
/*   Updated: 2018/10/29 22:30:37 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtoupper(char *str)
{
	char	*new;
	int		i;

	new = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			new[i] = str[i] - 32;
		else
			new[i] = str[i];
		++i;
	}
	new[i] = '\0';
	return (new);
}
