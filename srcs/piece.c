/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:21:41 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/25 22:01:55 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	fine_piece_size(t_piece *piece, char *line)
{
	int			i;

	i = 0;
	while (ft_isdigit(line[i]) == 0)
		++i;
	piece->height = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]) == 1)
		++i;
	++i;
	piece->width = ft_atoi(&line[i]);
	// ft_printf("\nHeight: %d\n", piece->height);
	// ft_printf("Width: %d\n", piece->width);
	piece->size = piece->height * piece->width;
	// ft_printf("Size: %d\n\n", piece->size);
}

void	size_of_piece(t_filler *filler, char *line)
{
	if (ft_strncmp(line, "Piece", 5) == 0)
	{
		filler->piece = (t_piece*)malloc(sizeof(t_piece));
		fine_piece_size(filler->piece, line);
	}
}

void	piece(t_filler *filler, char *line)
{
	filler->piece->field = (char**)malloc(sizeof(char*)\
		* (filler->piece->height));
	filler->piece->field[filler->piece->height] = NULL;
	save_map(filler->piece, line, 0);
}
