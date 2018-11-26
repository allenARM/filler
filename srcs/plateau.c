/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plateau.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:22:25 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/25 17:22:34 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	save_map(t_piece *piece, char *line, int spaces)
{
	int			k;
	static int	j;

	k = 0;
	j = 0;
	piece->field[j] = (char*)malloc(sizeof(char) * (piece->width + 1));
	while (k <= piece->width)
	{
		piece->field[j][k] = line[k + spaces];
		k++;
	}
	piece->field[j][k] = '\0';
	b_printf("%s\n", piece->field[j]);
	j++;
}

void	plateau(t_filler *filler, char *line)
{
	if (ft_strncmp(line, "Plateau", 7) == 0)
	{
		filler->map = (t_piece*)malloc(sizeof(t_piece));
		fine_piece_size(filler->map, line);
	}
	if (line[3] == ' ')
	{
		filler->map->field = (char**)malloc(sizeof(char*)\
			* (filler->map->height));
		filler->map->field[filler->map->height] = NULL;
		save_map(filler->map, line, 4);
	}
}
