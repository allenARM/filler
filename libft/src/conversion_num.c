/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:40:29 by amelikia          #+#    #+#             */
/*   Updated: 2018/10/31 16:16:08 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	make_d_i_smaller(t_arg *data, char **answer)
{
	if (*answer[0] == '-')
	{
		data->minus = 1;
		*answer = ft_update(*answer, ft_strsub(*answer, 1,
			ft_strlen(*answer) - 1));
	}
}

char	*conversion_d_i(va_list arg, t_arg *data)
{
	char		*answer;
	intmax_t	tmp;

	answer = ft_strnew(1);
	tmp = va_arg(arg, intmax_t);
	if (!ft_strcmp(data->format, "ll"))
		tmp = (long long)tmp;
	else if (!ft_strcmp(data->format, "l"))
		tmp = (long int)tmp;
	else if (!ft_strcmp(data->format, "hh"))
		tmp = (char)tmp;
	else if (!ft_strcmp(data->format, "h"))
		tmp = (short int)tmp;
	else if (!ft_strcmp(data->format, "j"))
		tmp = (intmax_t)tmp;
	else if (!ft_strcmp(data->format, "z"))
		tmp = (size_t)tmp;
	else
		tmp = (int)tmp;
	answer = ft_update(answer, ft_itoa_intmax(tmp));
	make_d_i_smaller(data, &answer);
	return (answer);
}

char	*conversion_u_cd_cu(va_list arg, t_arg *data)
{
	char		*answer;
	intmax_t	tmp;

	answer = ft_strnew(1);
	tmp = va_arg(arg, uintmax_t);
	if (!ft_strcmp(data->format, "ll"))
		tmp = (unsigned long long)tmp;
	else if (!ft_strcmp(data->format, "l"))
		tmp = (unsigned long)tmp;
	else if (!ft_strcmp(data->format, "hh"))
		tmp = (unsigned char)tmp;
	else if (!ft_strcmp(data->format, "h"))
		tmp = (unsigned short)tmp;
	else if (!ft_strcmp(data->format, "j"))
		tmp = (uintmax_t)tmp;
	else if (!ft_strcmp(data->format, "z"))
		tmp = (size_t)tmp;
	else
		tmp = (unsigned int)tmp;
	answer = ft_update(answer, ft_itoa_unsigned(tmp));
	return (answer);
}
