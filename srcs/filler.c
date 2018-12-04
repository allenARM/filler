/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 18:36:39 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/04 14:19:04 by amelikia         ###   ########.fr       */
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

void	define_players(t_filler *filler, char *line)
{
	if (ft_strstr(line, "p1") && ft_strstr(line, "amelikia"))
	{
		filler->player = 'O';
		filler->enemy = 'X';
	}
	else if (ft_strstr(line, "p2") && ft_strstr(line, "amelikia"))
	{
		filler->player = 'X';
		filler->enemy = 'O';
	}
}

void	read_everything(t_filler *filler, char *line, int *index)
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

int		main(void)
{
	t_filler		filler;
	char			*line;
	int				index;

	index = 0;
	line = NULL;
	ft_bzero(&filler, sizeof(t_filler));
	while (get_next_line(0, &line) > 0)
	{
		read_everything(&filler, line, &index);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	ft_clean_arr(&filler.map);
	return (0);
}
