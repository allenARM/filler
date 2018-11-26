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
# include "libft/libft.h"
# include "b_printf/includes/printf.h"

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
	t_piece		*map;
	t_piece		*piece;
	t_piece		*goal;
	int			is_on;
}				t_filler;

void			finepiecesize(t_piece *piece, char *line);
void			size_of_piece(t_filler *filler, char *line);
void			piece(t_filler *filler, char *line);
void			save_map(t_piece *piece, char *line, int spaces);
void			plateau(t_filler *filler, char *line);
void			readlines(t_filler *filler);

#endif
