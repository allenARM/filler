/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 18:36:39 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/26 10:56:40 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	reading_loop(t_filler *filler)
{
	char	*line;
	int		res;

	while ((res = get_next_line(1, &line)) > 0)
	{
		if (!ft_strncmp(line, "Plateau", 6))
		{
			read_map(line, filler);
			ft_strdel(&line);
		}
		else if (!ft_strncmp(line, "Piece", 4))
		{
			read_piece(line, filler);
			return (1);
		}
		else
			ft_strdel(&line);
	}
	return (0);
}

int		main(void)
{
	t_filler	*filler;
	char		*line;

	line = NULL;
	filler = malloc(sizeof(t_filler));
	if (get_next_line(0, &line) && ft_strlen(line) > 10 && \
			ft_strncmp(line, "$$$ exec p", 10) == 0 && (line[10] == '1' \
			|| line[10] == '2'))
	{
		if (line[10] == '1')
		{
			filler->enemy.symbol = 'O';
			filler->player.symbol = 'X';
		}
		else
		{
			filler->player.symbol = 'O';
			filler->enemy.symbol = 'X';
		}
		ft_strdel(&line);
		while (1)
		{
			reading_loop(filler);
			write(1, "8 2\n", 4);
		}
	}
	return (0);
}
