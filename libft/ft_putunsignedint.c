/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignedint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 09:35:59 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/19 09:36:06 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunsignedint(unsigned int n)
{
	if (n >= 10)
	{
		ft_putunsignedint(n / 10);
		ft_putunsignedint(n % 10);
	}
	if (n < 10)
		ft_putchar(n + 48);
}
