/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 18:36:39 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/03 19:32:52 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

// void	read_player(char *line, t_filler *filler)
// {
// 	if (ft_strlen(line) == 31 && \
// 			ft_strncmp(line, "$$$ exec p", 10) == 0 && (line[10] == '1' \
// 			|| line[10] == '2'))
// 	{
// 		if (line[10] == '1')
// 		{
// 			filler->enemy.symbol = 'X';
// 			filler->player.symbol = 'O';
// 		}
// 		else
// 		{
// 			filler->player.symbol = 'X';
// 			filler->enemy.symbol = 'O';
// 		}
// 	}
// }
//
// void	get_board(char *line, t_filler *filler)
// {
// 	static int i = 0;
// 	if (!filler->player.symbol)
// 	{
// 		read_player(line, filler);
// 		return ;
// 	}
// 	else if (!ft_strncmp(line, "Plateau", 7))
// 	{
// 		find_dimenshions(line, &filler->map);
// 		return ;
// 	}
// 	else if (!ft_strncmp(line, "Piece", 5))
// 	{
// 		find_dimenshions(line, &filler->piece);
// 		return ;
// 	}
// 	else if (!ft_strncmp(line, "    01234567890123456", 21) ||
// 	!ft_strncmp(line, "l", 1) || !ft_strncmp(line, "#", 1) ||
// 	!ft_strncmp(line, "$$$ exec p2 :", 13))
// 		return ;
// 	if (filler->piece.height == 0)
// 	{
// 		filler->map.field[i] = ft_strdup(&line[4]);
// 		i++;
// 		if (filler->map.height == i)
//  			i = 0;
// 		return ;
// 	}
// 	if (filler->piece.height && i < filler->piece.height)
// 	{
// 		filler->piece.field[i] = ft_strdup(line);
// 		i++;
// 		if (i == (filler->piece.height))
// 			// ft_printf("8 2\n");
// 			solver(filler);
// 		return ;
// 	}
// 	i = 0;
// }
//
// int		reading_loop(t_filler *filler)
// {
// 	char	*line;
//
// 	while (get_next_line(0, &line) > 0)
// 	{
// 		// get_board(line, filler);
// 		ft_strdel(&line);
// 	}
// 	return (1);
// }
//
// int		main(void)
// {
// 	t_filler	filler;
// 	char		*line;
//
// 	line = NULL;
// 	ft_bzero(&filler, sizeof(t_filler));
// 	reading_loop(&filler);
// 	return (0);
// }

void        define_map(t_filler *filler, char *line)
{
	int		i;

	i = 0;
	while (ft_isdigit(line[i]) == 0)
		++i;
	filler->map_y = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]) == 1)
		++i;
	++i;
	filler->map_x = ft_atoi(&line[i]);
	filler->map = ft_create_arr(filler->map_y, filler->map_x);
}

void        define_piece(t_filler *filler, char *line)
{
	int		i;

	i = 0;
	while (ft_isdigit(line[i]) == 0)
		++i;
	filler->piece_y = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]) == 1)
		++i;
	++i;
	filler->piece_x = ft_atoi(&line[i]);
	filler->piece = ft_create_arr(filler->piece_y, filler->piece_x);
}

void        define_players(t_filler *filler, char *line)
{
	if (ft_strstr(line, "p1") && ft_strstr(line, "login"))
	{
		filler->player = 'O';
		filler->enemy = 'X';
	}
	else if (ft_strstr(line, "p2") && ft_strstr(line, "login"))
	{
		filler->player = 'X';
		filler->enemy = 'O';
	}
}

int         main()
{
	t_filler    filler;
	char        *line;
	int         index;

	index = 0;
	ft_bzero(&filler, sizeof(t_filler));
		line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (!filler.player)
			define_players(&filler, line);
		if (!filler.map_y && !filler.map_x && ft_strstr(line, "Plateau"))
			define_map(&filler, line);
		if (line[0] == '0' && filler.map)
		{
			ft_strcpy(filler.map[index++], line + 4);
			if (index == filler.map_y)
				index = 0;
		}
		if (ft_strstr(line, "Piece"))
			define_piece(&filler, line);
		if (filler.piece && (line[0] == '*' || line[0] == '.'))
		{
			ft_strcpy(filler.piece[index++], line);
			if (index == filler.piece_y)
			{
				index = 0;
				// ft_printf("8 2\n");
				solver(&filler);
				// ft_memdel_arlen((void**)filler.piece);
			}
		}
		ft_strdel(&line);
	}
	// ft_memdel_arlen((void**)filler.map);
	return (0);
}
