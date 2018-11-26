/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_o_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:42:00 by amelikia          #+#    #+#             */
/*   Updated: 2018/10/31 16:04:00 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	*conversion_o_co(va_list arg, t_arg *data)
{
	char		*answer;
	intmax_t	tmp;

	answer = ft_strnew(1);
	tmp = va_arg(arg, uintmax_t);
	if (!ft_strcmp(data->format, "ll"))
		tmp = (unsigned long long int)tmp;
	else if (!ft_strcmp(data->format, "l"))
		tmp = (unsigned long int)tmp;
	else if (!ft_strcmp(data->format, "hh"))
		tmp = (unsigned char)tmp;
	else if (!ft_strcmp(data->format, "h"))
		tmp = (unsigned short int)tmp;
	else if (!ft_strcmp(data->format, "j"))
		tmp = (uintmax_t)tmp;
	else if (!ft_strcmp(data->format, "z"))
		tmp = (size_t)tmp;
	else
		tmp = (unsigned int)tmp;
	answer = ft_update(answer, ft_itoa_base_unsigned(tmp, 8));
	if (data->hashtag == 1 && tmp != 0)
		answer = ft_update(answer, ft_strjoin("0", answer));
	return (answer);
}

char	*conversion_x_cx(va_list arg, t_arg *data)
{
	char		*answer;
	intmax_t	tmp;

	answer = ft_strnew(1);
	tmp = va_arg(arg, uintmax_t);
	if (!ft_strcmp(data->format, "ll"))
		tmp = (unsigned long long int)tmp;
	else if (!ft_strcmp(data->format, "l"))
		tmp = (unsigned long int)tmp;
	else if (!ft_strcmp(data->format, "hh"))
		tmp = (unsigned char)tmp;
	else if (!ft_strcmp(data->format, "h"))
		tmp = (unsigned short int)tmp;
	else if (!ft_strcmp(data->format, "j"))
		tmp = (uintmax_t)tmp;
	else if (!ft_strcmp(data->format, "z"))
		tmp = (size_t)tmp;
	else
		tmp = (unsigned int)tmp;
	answer = ft_update(answer, ft_itoa_base_unsigned(tmp, 16));
	if (data->hashtag == 1 && tmp != 0 && data->zero_pending == 0)
		answer = ft_update(answer, ft_strjoin("0x", answer));
	if (data->type == 'X')
		answer = ft_update(answer, ft_strtoupper(answer));
	return (answer);
}
