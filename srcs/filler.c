/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 18:36:39 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/03 22:13:23 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	define_map(t_filler *filler, char *line)
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

void	define_piece(t_filler *filler, char *line)
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

void		define_players(t_filler *filler, char *line)
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

void	read_map(t_filler *filler, char *line, int *index)
{
	if (!filler->player)
		define_players(filler, line);
	if (!filler->map_y && !filler->map_x && ft_strstr(line, "Plateau"))
		define_map(filler, line);
	if (line[0] == '0' && filler->map)
	{
		ft_strcpy(filler->map[(*index)++], line + 4);
		if (*(index) == filler->map_y)
			*index = 0;
	}
}

void	read_piece(t_filler *filler, char *line, int *index)
{
	if (ft_strstr(line, "Piece"))
		define_piece(filler, line);
	if (filler->piece && (line[0] == '*' || line[0] == '.'))
	{
		ft_strcpy(filler->piece[(*index)++], line);
		if (*(index) == filler->piece_y)
		{
			*index = 0;
			solver(filler);
			ft_clean_arr(&filler->piece);
		}
	}
}

void	reading_loop(t_filler *filler, char *line, int index)
{
	while (get_next_line(0, &line) > 0)
	{
		read_map(filler, line, &index);
		read_piece(filler, line, &index);
		ft_strdel(&line);
	}
	ft_clean_arr(&filler->map);
}

int		main(void)
{
	t_filler		filler;
	char			*line;
	int				index;

	index = 0;
	ft_bzero(&filler, sizeof(t_filler));
	line = NULL;
	reading_loop(&filler, line, index);
	return (0);
}
