/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 13:23:50 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/03 17:00:19 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	source_len;
	char	*result;

	source_len = ft_strlen(src) + 1;
	result = (char *)ft_memcpy(dst, src, source_len);
	return (result);
}
