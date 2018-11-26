/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:45:16 by amelikia          #+#    #+#             */
/*   Updated: 2018/10/31 16:04:00 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	if_unusial(va_list arg, const char *s, int *i, t_arg *data)
{
	makezero(data);
	parse_data(s, &*i, data);
	parse_width(arg, s, &*i, data);
	parse_accuracy(arg, s, &*i, data);
	parse_format(&s[*i], &*i, data);
	parse_type(s, &*i, data);
	if (data->right_pending == 1)
		data->zero_pending = 0;
}

void	data_use(va_list arg, t_arg *data)
{
	char	*res;

	res = type_define(arg, data);
	g_word = ft_update(g_word, ft_strjoin(g_word, res));
	free(res);
}

void	after_percentage_checker(va_list arg, const char *s, int *i)
{
	t_arg	*data;

	data = (t_arg*)malloc(sizeof(t_arg));
	if_unusial(arg, s, &*i, data);
	data_use(arg, data);
	free(data->format);
	free(data);
}
