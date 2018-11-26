/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:43:39 by amelikia          #+#    #+#             */
/*   Updated: 2018/10/31 16:26:36 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	*adding_precision_string(t_arg *data, char *str)
{
	char	*tmp;

	if (data->type != 'S' && data->type != 's')
	{
		tmp = ft_strdup(str);
		return (tmp);
	}
	if (data->precision == 0)
	{
		tmp = ft_strnew(1);
		return (tmp);
	}
	if (data->precision >= (int)ft_strlen(str))
	{
		tmp = ft_strdup(str);
		return (tmp);
	}
	str = ft_strsub(str, 0, data->precision);
	return (str);
}

char	*precision_number_child(char *str, t_arg *data)
{
	char	*tmp;
	int		i;

	tmp = (char *)malloc(sizeof(char) * data->precision + 1);
	i = 0;
	while (i < (data->precision - (int)ft_strlen(str)))
		tmp[i++] = '0';
	while (*str)
	{
		tmp[i++] = *str;
		str++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*adding_precision_number(t_arg *data, char *str)
{
	char	*tmp;

	if (data->type != 'd' && data->type != 'i' && \
			data->type != 'U' && data->type != 'u' && \
			data->type != 'D' && data->type != 'X' && \
			data->type != 'o' && data->type != 'x' && \
			data->type != 'O')
	{
		tmp = ft_strdup(str);
		return (tmp);
	}
	if (!((data->type == 'o' || data->type == 'O') && data->hashtag == 1))
		if (data->precision == 0 && !ft_strcmp(str, "0"))
		{
			tmp = ft_strnew(1);
			return (tmp);
		}
	if (data->precision <= (int)ft_strlen(str))
	{
		tmp = ft_strdup(str);
		return (tmp);
	}
	return (precision_number_child(str, data));
}
