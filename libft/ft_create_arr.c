/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:45:07 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/05 19:23:10 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_create_arr(int height, int width)
{
	char	**arr;
	int		i;

	arr = (char **)malloc(sizeof(char *) * (height + 1));
	i = 0;
	while (i < height)
		arr[i++] = (char *)malloc(sizeof(char) * (width + 1));
	arr[i] = NULL;
	return (arr);
}
