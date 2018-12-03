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
	piece->field = (char **)malloc(sizeof(char *) * piece->height + 1);
	piece->field[piece->height] = NULL;
}

int			read_map(char *line, t_piece *map)
{
	int		i;

	find_dimenshions(line, map);
	get_next_line(0, &line);
	// ft_strdel(&line);
	map->field = (char **)malloc(sizeof(char *) * map->height + 1);
	map->field[map->height] = NULL;
	i = 0;
	while (i < map->height)
	{
		get_next_line(0, &line);
		map->field[i] = ft_strdup((const char *)(&line[4]));
		// ft_strdel(&line);
		++i;
	}
	return (0);
}

int			read_piece(char *line, t_filler *filler)
{
	int		i;
	// char	*fu;

	// fu = ft_strnew(1);
	find_dimenshions(line, &filler->piece);
	// ft_strdel(&line);
	filler->piece.field = (char **)malloc(sizeof(char *) * filler->piece.height + 1);
	filler->piece.field[filler->piece.height] = NULL;
	i = 0;
	while (i < filler->piece.height)
	{
		// ft_printf("--%d\n", piece->height);
		get_next_line(0, &line);
		// piece->field[i] = (char *)malloc(sizeof(char *) * (piece->width + 1));
		// piece->field[i] = ft_strcpy(piece->field[i], *line);
		// piece->field[i][piece->width] = '\0';
		filler->piece.field[i] = ft_strdup(line);
		// ft_strdel(&fu);
		++i;
	}
	// fu = (char*)malloc(sizeof(char) * piece->width);
	// read(1, &fu, piece->width);
	// get_next_line(1, line);
	// ft_printf("\n--\n%s\n---\n", piece->field[i]);
	solver(filler);
	return (0);
}
