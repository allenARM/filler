/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 18:39:51 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/25 17:24:51 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/libft.h"

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_player
{
	char		symbol; // 'x' or 'o'
	t_point		*start; // 'where is x or o'
}				t_player;

typedef	struct	s_piece
{
	int			width;
	int			height;
	int			size;
	char		**field;
}				t_piece;

typedef	struct	s_filler
{
	t_player	enemy;
	t_player	player;
	t_piece		map;
	t_piece		piece;
	t_point		*goal;
	int			is_on;
}				t_filler;

void	find_dimenshions(char *line, t_piece *piece);
int			read_map(char *line, t_filler *filler);
int			read_piece(char *line, t_filler *filler);
void	free_filler(t_filler *filler);
int         solver(t_filler filler);

#endif
