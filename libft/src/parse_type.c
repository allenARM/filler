/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:33:11 by amelikia          #+#    #+#             */
/*   Updated: 2018/10/31 16:06:37 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	parse_type_dig(const char *s, int *i, t_arg *data)
{
	if (s[*i] == 'd')
		data->type = 'd';
	if (s[*i] == 'D')
		data->type = 'D';
	if (s[*i] == 'i')
		data->type = 'i';
	if (s[*i] == 'o')
		data->type = 'o';
	if (s[*i] == 'O')
		data->type = 'O';
	if (s[*i] == 'u')
		data->type = 'u';
	if (s[*i] == 'U')
		data->type = 'U';
	if (s[*i] == 'x')
		data->type = 'x';
	if (s[*i] == 'X')
		data->type = 'X';
}

void	parse_type_etc(const char *s, int *i, t_arg *data)
{
	if (s[*i] == 's')
		data->type = 's';
	if (s[*i] == 'S')
		data->type = 'S';
	if (s[*i] == 'p')
		data->type = 'p';
	if (s[*i] == 'c')
		data->type = 'c';
	if (s[*i] == 'C')
		data->type = 'C';
	if (s[*i] == 'b')
		data->type = 'b';
	if (s[*i] == '%')
		data->type = '%';
}

void	parse_type(const char *s, int *i, t_arg *data)
{
	parse_type_etc(s, &*i, data);
	parse_type_dig(s, &*i, data);
	(*i)++;
}
