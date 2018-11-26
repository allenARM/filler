/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_define.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:36:50 by amelikia          #+#    #+#             */
/*   Updated: 2018/10/31 23:17:34 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	type_define_symbol(char **tmp, va_list arg, t_arg *data)
{
	if (data->type == 's' || data->type == 'S')
		*tmp = ft_update(*tmp, conversion_s_ws(arg, data));
	else if (data->type == 'c' || data->type == 'C')
		*tmp = ft_update(*tmp, conversion_c_wc(arg, data));
	else if (data->type == 'i' || data->type == 'd')
		*tmp = ft_update(*tmp, conversion_d_i(arg, data));
	else if (data->type == 'p')
		*tmp = ft_update(*tmp, conversion_p(arg));
	else if (data->type == 'D' || data->type == 'u' || data->type == 'U')
		*tmp = ft_update(*tmp, conversion_u_cd_cu(arg, data));
	else if (data->type == 'o' || data->type == 'O')
		*tmp = ft_update(*tmp, conversion_o_co(arg, data));
	else if (data->type == 'x' || data->type == 'X')
		*tmp = ft_update(*tmp, conversion_x_cx(arg, data));
	else if (data->type == 'b')
		*tmp = ft_update(*tmp, conversion_b(arg, data));
	else if (data->type == '%')
		*tmp = ft_update(*tmp, ft_bchar(1, '%'));
}

char	*type_define(va_list arg, t_arg *data)
{
	char	*tmp;

	tmp = ft_strnew(1);
	type_define_symbol(&tmp, arg, data);
	if (data->star_precision != 0)
	{
		tmp = ft_update(tmp, adding_precision_string(data, tmp));
		tmp = ft_update(tmp, adding_precision_number(data, tmp));
	}
	if (data->minus == 1)
		tmp = ft_update(tmp, adding_minus(data, tmp));
	else if (data->plus == 1)
		tmp = ft_update(tmp, adding_plus(data, tmp));
	else if (data->space == 1)
		tmp = ft_update(tmp, adding_space(data, tmp));
	if (data->width != 0 && data->null != 1)
		tmp = adding_width(data, tmp);
	return (tmp);
}
