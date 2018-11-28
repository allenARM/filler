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

int			read_map(char *line, t_filler *filler)
{
	int		i;

	find_dimenshions(line, &(filler->map));
	ft_strdel(&line);
	get_next_line(0, &line);
	ft_strdel(&line);
	filler->map.field = (char **)malloc(sizeof(char *) * (filler->map.height + 1));	
	i = 0;
	while (i < filler->map.height)
	{
		get_next_line(0, &line);
		filler->map.field[i] = ft_strdup((const char *)(&line[4]));
		ft_strdel(&line);
		++i;
	}
	return (0);
}

int			read_piece(char *line, t_filler *filler)
{
	int		i;

	find_dimenshions(line, &(filler->piece));
	ft_strdel(&line);
	filler->piece.field = (char **)malloc(sizeof(char *) * (filler->piece.height + 1));
	i = 0;
	while (i < filler->piece.height)
	{
		get_next_line(0, &line);
		filler->piece.field[i] = (char *)malloc(sizeof(char *) * (filler->piece.width + 1));
		filler->piece.field[i] = ft_strcpy(filler->piece.field[i], (const char *)line);
		ft_strdel(&line);
		++i;

	}
	return (0);
}