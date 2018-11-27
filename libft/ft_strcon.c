/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 15:55:16 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/24 11:21:41 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcon(char **arr, char *c)
{
	int		i;
	char	*str;
	char	*tmp;

	i = 0;
	str = ft_strnew(1);
	while (arr[i])
	{
		tmp = ft_strjoin(str, arr[i]);
		free(str);
		str = tmp;
		tmp = ft_strjoin(str, c);
		free(str);
		str = tmp;
		++i;
	}
	return (str);
}
