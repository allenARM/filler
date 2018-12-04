/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 22:19:28 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/04 15:00:09 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		small_check(t_filler *filler, int i, int j, int *count)
{
	if (i < filler->map_y && j < filler->map_x)
	{
		if (filler->map[i][j])
		{
			if (filler->map[i][j] == filler->player || \
				filler->map[i][j] == filler->player + 32)
				(*count)++;
			if (filler->map[i][j] == filler->enemy || \
				filler->map[i][j] == filler->enemy + 32)
				return (0);
		}
		else
			return (0);
	}
	else
		return (0);
	return (1);
}

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
				if (small_check(filler, i_piece + i, j_piece + j, &count) == 0)
					return (0);
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

void	simple_placing(t_filler *filler, t_point *answer)
{
	int			**map;
	int			min_sum;
	int			tmp;
	int			i;
	int			j;

	i = -1;
	min_sum = 1000000;
	map = heatmap(filler->player, filler->enemy, filler->map);
	while (filler->map[++i])
	{
		j = -1;
		while (filler->map[i][++j])
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
	}
	ft_clean_int_arr(&map);
}

int		solver(t_filler *filler)
{
	t_point	*answer;

	answer = malloc(sizeof(t_point *));
	answer->y = 0;
	answer->x = 0;
	simple_placing(filler, answer);
	ft_printf("%d %d\n", answer->y, answer->x);
	free(answer);
	return (0);
}
