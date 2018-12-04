/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_int_arr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:58:24 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/04 14:58:36 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clean_int_arr(int ***map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!(map)[i])
		return ;
	while ((*map)[i])
		i++;
	while (j < i)
	{
		free((*map)[j]);
		j++;
	}
	free(*map);
}
