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

void	find_dimenshions(char *line, t_piece *piece)
{
	int		i;

	i = 0;
	while (ft_isdigit(line[i]) == 0)
		++i;
	piece->height = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]) == 1)
		++i;
	++i;
	piece->width = ft_atoi(&line[i]);
	piece->size = piece->height * piece->width;
}

int			read_map(t_piece *piece)
{
	int		i;
	char	*line;

	if (get_next_line(0, &line) != 1)
		return (-1);
	find_dimenshions(line, piece);
	piece->field = ft_create_arr(piece->height, piece->width);
	if (get_next_line(0, &line) != 1)
		return (-1);
	ft_strdel(&line);
	i = 0;
	while (i < piece->height)
	{
		if (get_next_line(0, &line) != 1)
			return (-1);
		piece->field[i] = ft_strsub(line, 4, ft_strlen(line) - 4);
		ft_strdel(&line);
		++i;
	}
	return (0);
}

int			read_piece(t_piece *piece)
{
	int		i;
	char	*line;

	if (get_next_line(0, &line) != 1)
		return (-1);
	find_dimenshions(line, piece);
	piece->field = ft_create_arr(piece->height, piece->width);
	i = 0;
	while (i < piece->height)
	{
		if (get_next_line(0, &line) != 1)
			return (-1);
		piece->field[i] = ft_strsub(line, 0, ft_strlen(line) - 0);
		ft_strdel(&line);
		++i;
	}
	return (0);
}

void	free_filler(t_filler *filler)
{
	int	i;

	i = 0;
	ft_clean_arr(&filler->map.field);
	ft_clean_arr(&filler->piece.field);
}

int	reading_loop(t_filler *filler)
{
	while (1)
	{
		if (read_map(&(filler->map)) == -1)
			return (-1);
		// if (read_piece(&(filler->piece)) == -1)
		// 	return (-1);
		// solving
		// filler = NULL;
		ft_printf("8 2\n");
	}
	return (0);
	// while (get_next_line(0, &line) > -1)
	// {
	// 	if (!line)
	// 		continue ;
	// 	if (!ft_strncmp(line, "Plateau ", 8))
	// 	{
	// 		read_piece(line, &(filler->map), 4);
	// 	}
	// if (!ft_strncmp(line, "Piece ", 6))
	// 	{
	// 		write(1, "bla", 3);
	// 		read_piece(line, &(filler->piece), 0);
	// 		// send_coordinates(filler);
	// 		ft_putnbr(8);
	// 		ft_putchar(' ');
	// 		ft_putnbr(2);
	// 		ft_putchar('\n');
	// 		// free_filler(filler);
	// 	}
	// 	ft_strdel(&line);
	// }
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
		reading_loop(filler);
	}
	return (0);
}
