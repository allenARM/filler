/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:20:53 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/25 20:17:29 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	readlines(t_filler *filler)
{
	char		*line;
	int			j;

	j = 0;
	while (get_next_line(0, &line) != -1)
	{
		plateau(filler, line);
		sizeofpiece(filler, line);
		if (line[0] != 'P' && ft_strncmp(line, "    ", 4) != 0\
			&& line[0] != '0')
		{
			piece(filler, line);
			free(line);
			if (j == (filler->piece->height - 1))
				break ;
			j++;
		}
	}
	b_printf("LOL\n");
}
