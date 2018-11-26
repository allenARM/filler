/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizeofint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 18:16:02 by amelikia          #+#    #+#             */
/*   Updated: 2018/10/27 15:02:54 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_sizeofint(int num, int base)
{
	int size;

	if (num == 0)
		return (0);
	size = 1;
	while (num >= 10)
	{
		num = num / base;
		size++;
	}
	return (size);
}
