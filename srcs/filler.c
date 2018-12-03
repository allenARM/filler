/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 18:36:39 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/03 15:04:10 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	read_player(char *line, t_filler *filler)
{
	if (ft_strlen(line) == 31 && \
			ft_strncmp(line, "$$$ exec p", 10) == 0 && (line[10] == '1' \
			|| line[10] == '2'))
	{
		if (line[10] == '1')
		{
			filler->enemy.symbol = 'X';
			filler->player.symbol = 'O';
		}
		else
		{
			filler->player.symbol = 'X';
			filler->enemy.symbol = 'O';
		}
	}
}

void	get_board(char *line, t_filler *filler)
{
	static int i = 0;

	if (!filler->player.symbol)
	{
		read_player(line, filler);
		return ;
	}
	else if (!ft_strncmp(line, "Plateau", 7))
	{
		find_dimenshions(line, &filler->map);
		return ;
	}
	else if (!ft_strncmp(line, "Piece", 5))
	{
		find_dimenshions(line, &filler->piece);
		return ;
	}
	else if (!ft_strncmp(line, "    01234567890123456", 21) ||
	!ft_strncmp(line, "l", 1) || !ft_strncmp(line, "#", 1) ||
	!ft_strncmp(line, "$$$ exec p2 :", 13))
		return ;
	if (filler->piece.height == 0)
	{
		// ft_printf("8 2\n");

		filler->map.field[i] = ft_strdup(&line[4]);
		i++;
		if (i > 7)
			ft_printf("%d %d\n", filler->map.height, i);
		// if (filler->map.height == i)
		// {
		// 	ft_printf("%d %d\n", filler->map.height, i);
 		// 	i = 0;
		// }
		return ;
	}
	if (filler->piece.height && i < filler->piece.height)
	{
		filler->piece.field[i] = ft_strdup(line);
		i++;
		if (i == (filler->piece.height))
		{
			ft_printf("8 2\n");
			solver(filler);
		}
		return ;
	}
	i = 0;
}

int		reading_loop(t_filler *filler)
{
	char	*line;

	// filler = NULL;
	while (get_next_line(0, &line) > 0)
	{
		// ft_putstr_fd(line, 1);
		// ft_putchar('\n');
		// if (!filler->player.symbol)
			// read_player(line, filler);
		// else
			get_board(line, filler);
		ft_strdel(&line);
	}
	return (1);
}

int		main(void)
{
	t_filler	filler;
	char		*line;

	line = NULL;
	ft_bzero(&filler, sizeof(t_filler));
	reading_loop(&filler);
	return (0);
}
