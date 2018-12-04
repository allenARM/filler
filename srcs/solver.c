#include "filler.h"

int		check_placement(t_filler *filler, int i, int j)
{
	int	i_piece;
	int	j_piece;
	int	count;

	i_piece = 0;
	j_piece = 0;
	count = 0;
	while (filler->piece[i_piece])
	{
		j_piece = 0;
		while (filler->piece[i_piece][j_piece])
		{
			if (filler->piece[i_piece][j_piece] == '*')
			{
				if (i_piece + i < filler->map_y && j_piece + j < filler->map_x)
				{
					if (filler->map[i_piece + i][j_piece + j])
					{
						if (filler->map[i_piece + i][j_piece + j] == filler->player || filler->map[i_piece + i][j_piece + j] == filler->player + 32)
							++count;
						if (filler->map[i_piece + i][j_piece + j] == filler->enemy || filler->map[i_piece + i][j_piece + j] == filler->enemy + 32)
							return (0);
					}
					else
						return (0);
				}
				else
					return (0);
			}
			++j_piece;
		}
		++i_piece;
	}
	return (count);
}

int		check_heat(int **map, t_filler *filler, int i, int j)
{
	int i_piece;
	int j_piece;
	int total;

	i_piece = 0;
	j_piece = 0;
	total = 0;
	while (filler->piece[i_piece])
	{
		j_piece = 0;
		while (filler->piece[i_piece][j_piece])
		{
			if (filler->piece[i_piece][j_piece] == '*')
				total += map[i_piece + i][j_piece + j];
			++j_piece;
		}
		++i_piece;
	}
	return (total);
}

void	ft_clean_int_arr(int ***map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!(map)[i])
		return ;
	while ((*map)[i])
		i++;
	while (j < i)
	{
		free((*map)[j]);
		j++;
	}
	free(*map);
}

t_point		*simple_placing(t_filler *filler)
{
	t_point		*answer;
	int			**map;
	int			min_sum;
	int			tmp;
	int			i;
	int			j;

	i = 0;
	min_sum = 1000000;
	map = heatmap(filler->map);
	answer = malloc(sizeof(t_point *));
	answer->y = 0;
	answer->x = 0;
	while (filler->map[i])
	{
		j = 0;
		while (filler->map[i][j])
		{
			if (check_placement(filler, i, j) == 1)
			{
				tmp = check_heat(map, filler, i, j);
				if (min_sum > tmp)
				{
					min_sum = tmp;
					answer->y = i;
					answer->x = j;
				}
			}
			++j;
		}
		++i;
	}
	ft_clean_int_arr(&map);
	return (answer);
}

int		solver(t_filler *filler)
{
	t_point	*answer;

	answer = simple_placing(filler);
	ft_printf("%d %d\n", answer->y, answer->x);
	free(answer);
	return (0);
}
