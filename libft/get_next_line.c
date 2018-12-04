/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 13:54:14 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/03 21:31:07 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_charfind(char *s1, const char s2)
{
	char	*s1o;
	char	*cpy;

	cpy = ft_strnew(ft_strlen(s1) + 1);
	cpy = ft_strcpy(cpy, s1);
	s1o = cpy;
	if (!s2)
		return (cpy);
	while (*cpy)
		cpy++;
	*cpy++ = s2;
	*cpy = '\0';
	free(s1);
	return (s1o);
}

static int	clean_buffer(char *buff, char **line, int i, int first)
{
	while (buff[++i])
	{
		if (buff[i] == -115)
			continue ;
		if (buff[i] == '\n' && first == 0)
		{
			*line[0] = 0;
			buff[i] = -115;
			return (1);
		}
		else if (buff[i] != '\n')
		{
			*line = ft_charfind(*line, buff[i]);
			buff[i] = -115;
			first = 1;
		}
		else if (buff[i] == '\n' && first == 1)
		{
			buff[i] = -115;
			return (1);
		}
	}
	if (first == 1)
		return (2);
	return (0);
}

static void	end(char *buff, char **line, int i, int first_p)
{
	if (first_p == 1 && (buff[0] == '\n' || buff[0] == '\0'))
		*line[0] = 0;
	while (buff[++i])
	{
		if (first_p == -1)
			buff[i] = -115;
		else if (buff[i] != '\n')
		{
			if (first_p == 1)
			{
				*line[0] = buff[i];
				first_p = 0;
			}
			else
				*line = ft_charfind(*line, buff[i]);
			buff[i] = -115;
		}
		else
		{
			buff[i] = -115;
			break ;
		}
	}
}

static int	check_new(char *buff, char **line, int count, int *first_go)
{
	char	*tmp;
	char	*tmp1;

	if ((ft_strchr(buff, (int)'\n')) == NULL && *first_go)
	{
		*line = ft_strncpy(*line, buff, count);
		first_go = 0;
	}
	else if ((ft_strchr(buff, (int)'\n')) == NULL)
	{
		tmp = (char *)ft_memalloc(sizeof(tmp) * (count + 1));
		tmp = ft_strncpy(tmp, buff, count);
		tmp1 = ft_strjoin(*line, tmp);
		free(*line);
		free(tmp);
		*line = tmp1;
	}
	else if ((ft_strchr(buff, (int)'\n')) != NULL)
	{
		end(buff, line, (-1), *first_go);
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	buff[BUFF_SIZE];
	int			first_p;
	int			nb;
	int			count;

	if (BUFF_SIZE <= 0 || !line || (fd < 2 && fd != 0))
		return (-1);
	*line = (char *)ft_memalloc(sizeof(*line) * (BUFF_SIZE + 1));
	first_p = 1;
	if ((nb = clean_buffer(buff, line, -1, 0)) == 1)
		return (1);
	else
		first_p = 0;
	while ((count = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if ((check_new(buff, line, count, &first_p)) == 1)
			return (1);
		end(buff, line, (-1), (-1));
	}
	if (count == -1)
		return (-1);
	if (nb == 2 || **line)
		return (1);
	return (0);
}
