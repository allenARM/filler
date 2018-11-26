/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:21:41 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/25 17:22:03 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	finepiecesize(t_piece *piece, char *line)
{
	char		*tmp;
	int			j;
	int			i;

	j = 0;
	i = 0;
	tmp = ft_strnew(1);
	while (line[i] != ' ')
		i++;
	i++;
	while (line[i] != ' ')
		tmp = ft_strjoin(tmp, makestr(line[i++]));
	piece->height = ft_atoi(tmp);
	b_printf("Height: %d\n", piece->height);
	ft_bzero(tmp, 1);
	while (line[i] != ':')
		tmp = ft_strjoin(tmp, makestr(line[i++]));
	piece->width = ft_atoi(tmp);
	b_printf("Width: %d\n", piece->width);
	piece->size = piece->height * piece->width;
	b_printf("Size: %d\n", piece->size);
}

void	size_of_piece(t_filler *filler, char *line)
{
	if (ft_strncmp(line, "Piece", 5) == 0)
	{
		filler->piece = (t_piece*)malloc(sizeof(t_piece));
		finepiecesize(filler->piece, line);
	}
}

void	piece(t_filler *filler, char *line)
{
	filler->piece->field = (char**)malloc(sizeof(char*)\
		* (filler->piece->height));
	filler->piece->field[filler->piece->height] = NULL;
	savemap(filler->piece, line, 0);
}
