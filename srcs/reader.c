/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:20:53 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/25 22:26:22 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	readlines(t_filler *filler)
{
	char		*line;
	int			j;

	while (1)
	{
		j = 0;
		ft_bzero(filler, sizeof(filler));
		filler->piece = malloc(sizeof(t_piece));
		filler->piece->height = 0;
		// ft_bzero(filler->piece, sizeof(t_piece));
		while (get_next_line(0, &line) > 0)
		{
			plateau(filler, line);
			size_of_piece(filler, line);
			if (line[0] != 'P' && ft_strncmp(line, "    ", 4) != 0\
				&& line[0] != '0')
			{
				piece(filler, line);
				free(line);
				// ft_printf("\nPiece height == %d, j == %d\n", filler->piece->height - 1, j);
				j++;
			}
			if (j == (filler->piece->height - 1))
				break ;
		}
		// ft_printf("8 2\n");
		write(1, "8 2\n", 5);
		// algo
	}
}
