/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_w_and_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:36:10 by amelikia          #+#    #+#             */
/*   Updated: 2018/10/31 16:21:22 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	parse_width(va_list arg, const char *s, int *i, t_arg *data)
{
	int	tmp;
	int skip;

	if (s[*i] == '*')
	{
		tmp = va_arg(arg, int);
		data->star_width = 1;
		data->width = tmp;
		(*i)++;
	}
	else if (s[(*i)] == '0')
		(*i)++;
	else
	{
		tmp = ft_atoi(&s[*i]);
		skip = ft_sizeofint(tmp, 10);
		data->star_width = -1;
		data->width = tmp;
		*i += skip;
	}
}

void	parse_accuracy_child(const char *s, int *i, t_arg *data)
{
	int tmp;
	int skip;

	tmp = ft_atoi(&s[*i]);
	skip = ft_sizeofint(tmp, 10);
	data->star_precision = -1;
	data->precision = tmp;
	*i += skip;
}

void	parse_accuracy(va_list arg, const char *s, int *i, t_arg *data)
{
	int tmp;

	if (s[*i] == '.' && s[*i + 1] != '\0')
	{
		(*i)++;
		if (s[*i] == '*')
		{
			tmp = va_arg(arg, int);
			data->star_precision = 1;
			data->precision = tmp;
			(*i)++;
		}
		else if (s[(*i)] == '0')
		{
			(*i)++;
			data->star_precision = -1;
		}
		else
			parse_accuracy_child(s, &*i, data);
	}
}
