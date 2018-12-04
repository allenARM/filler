/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 18:39:51 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/03 19:32:05 by amelikia         ###   ########.fr       */
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

typedef	struct	s_filler
{
	char		enemy;
	char		player;
	char		**map;
	int			map_x;
	int			map_y;
	char		**piece;
	int			piece_x;
	int			piece_y;
}				t_filler;


int		solver(t_filler *filler);
int		**heatmap(char **map);

#endif
