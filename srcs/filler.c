/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 18:36:39 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/25 21:00:49 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_filler	filler;
	char		*line;

	ft_bzero(&filler, sizeof(filler));
	if (get_next_line(0, &line) == 1 && ft_strlen(line) == 30 && \
			ft_strncmp(line, "$$$ exec p", 10) == 0 && (line[10] == '1' \
			|| line[10] == '2'))
	{
		if (line[10] == '1')
		{
			filler.enemy.symbol = 'O';
			filler.player.symbol = 'X';
		}
		else
		{
			filler.player.symbol = 'O';
			filler.enemy.symbol = 'X';
		}
		ft_strdel(&line);
		readlines(&filler);
		//reading_loop(&filler);
	}
	return (0);
}
