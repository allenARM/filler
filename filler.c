/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 18:36:39 by amelikia          #+#    #+#             */
/*   Updated: 2018/10/16 12:35:06 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char *makestr(char c)
{
  char *s;

  s = (char*)malloc(sizeof(char) + 1);
  s[0] = c;
  s[1] = '\0';
  return (s);
}

void	finepiecesize(t_piece *piece, char *line)
{
	char		*tmp = "";
	int			j;
	int			i;

	j = 0;
	i = 0;
	while(line[i] != ' ')
		i++;
	i++;
	while(line[i] != ' ')
		tmp = ft_strjoin(tmp, makestr(line[i++]));
	piece->height = ft_atoi(tmp);
	b_printf("Height: %d\n", piece->height);
	ft_bzero(tmp, 1);
	while(line[i] != ':')
		tmp = ft_strjoin(tmp, makestr(line[i++]));
	piece->width = ft_atoi(tmp);
	b_printf("Width: %d\n", piece->width);
	piece->size = piece->height * piece->width;
	b_printf("Size: %d\n", piece->size);
}

void 	savemap(t_piece *piece, char *line, int spaces)
{
	int k;
	static int j = 0;

	k = 0;
	piece->field[j] = (char*)malloc(sizeof(char) * (piece->width + 1));
	while (k <= piece->width)
	{
		piece->field[j][k] = line[k + spaces];
		k++;
	}
	piece->field[j][k] = '\0';
	b_printf("%s\n", piece->field[j]);
	j++;
}

void 	plateau(t_filler *filler, char *line)
{
	if (ft_strncmp(line, "Plateau", 7) == 0)
	{
		filler->map = (t_piece*)malloc(sizeof(t_piece));
		finepiecesize(filler->map, line);
	}
	if (line[3] == ' ')
	{
		filler->map->field = (char**)malloc(sizeof(char*) * (filler->map->height));
		filler->map->field[filler->map->height] = NULL;
		savemap(filler->map, line, 4);
	}
}

void 	sizeofpiece(t_filler *filler, char *line)
{
	if (ft_strncmp(line, "Piece", 5) == 0)
	{
		filler->piece = (t_piece*)malloc(sizeof(t_piece));
		finepiecesize(filler->piece, line);
	}
}

void piece(t_filler *filler, char *line)
{
	filler->piece->field = (char**)malloc(sizeof(char*) * (filler->piece->height));
	filler->piece->field[filler->piece->height] = NULL;
	savemap(filler->piece, line, 0);
}

void	readlines(t_filler *filler)
{
	char		*line;
	int			j;

	while (1)
	{
		j = 0;
		while (get_next_line(0, &line) != -1)
		{
			plateau(filler, line);
			sizeofpiece(filler, line);
			if (line[0] != 'P' && ft_strncmp(line, "    ", 4) != 0 && line[0] != '0')
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
}

int main()
{
	t_filler	filler;
	char		*line;

	if (get_next_line(0, &line) == 1 && ft_strlen(line) == 29 && \
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
