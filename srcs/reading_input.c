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

int			read_map(char *line, t_piece *map)
{
	int		i;

	find_dimenshions(line, map);
	get_next_line(0, &line);
	ft_strdel(&line);
	map->field = (char **)malloc(sizeof(char *) * map->height + 1);	
	i = 0;
	while (i < map->height)
	{
		get_next_line(0, &line);
		map->field[i] = ft_strdup((const char *)(&line[4]));
		ft_strdel(&line);
		++i;
	}
	return (0);
}

int			read_piece(char *line, t_piece *piece)
{
	int		i;

	find_dimenshions(line, piece);
	ft_strdel(&line);
	piece->field = (char **)malloc(sizeof(char *) * piece->height + 1);
	i = 0;
	while (i < piece->height)
	{
		get_next_line(0, &line);
		piece->field[i] = (char *)malloc(sizeof(char *) * (piece->width + 1));
		piece->field[i] = ft_strcpy(piece->field[i], (const char *)line);
		ft_strdel(&line);
		++i;

	}
	return (0);
}