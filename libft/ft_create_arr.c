/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:05:30 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/26 18:08:40 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_create_arr(int height, int width)
{
	char	**arr;
	int		i;

	arr = (char **)malloc(sizeof(char *) * height + 1);
	i = 0;
	while (i < height)
		arr[i++] = (char *)malloc(sizeof(char) * width + 1);
	arr[i] = NULL;
	return (arr);
}
