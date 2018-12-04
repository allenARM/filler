/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 13:54:14 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/03 18:56:31 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static char		**checkforn(char **line, int fd, int len, char **str)
// {
// 	char	*tmp;
//
// 	*line = ft_strsub(str[fd], 0, len);
// 	tmp = ft_strdup(str[fd] + len + 1);
// 	free(str[fd]);
// 	str[fd] = tmp;
// 	return (str);
// }
//
// static int		newline(char **str, char **line, int fd, int vlu)
// {
// 	int		len;
//
// 	len = 0;
// 	while (str[fd][len] != '\n' && str[fd][len] != '\0')
// 		len++;
// 	if (str[fd][len] == '\n')
// 		checkforn(line, fd, len, str);
// 	else if (str[fd][len] == '\0')
// 	{
// 		if (vlu == BUFF_SIZE)
// 			return (get_next_line(fd, line));
// 		*line = ft_strdup(str[fd]);
// 		ft_strdel(&str[fd]);
// 	}
// 	return (1);
// }
//
// int				get_next_line(const int fd, char **line)
// {
// 	static char	*str[255];
// 	char		buffer[BUFF_SIZE + 1];
// 	char		*tmp;
// 	int			vlu;
//
// 	if (fd < 0 || line == NULL)
// 		return (-1);
// 	while ((vlu = read(fd, buffer, BUFF_SIZE)) > 0)
// 	{
// 		buffer[vlu] = '\0';
// 		if (str[fd] == NULL)
// 			str[fd] = ft_strnew(1);
// 		tmp = ft_strjoin(str[fd], buffer);
// 		free(str[fd]);
// 		str[fd] = tmp;
// 		if (ft_strchr(buffer, '\n'))
// 			break ;
// 	}
// 	if (vlu < 0)
// 		return (-1);
// 	else if (vlu == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
// 		return (0);
// 	return (newline(str, line, fd, vlu));
// }

static char	*ft_charcat(char *s1, const char s2)
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

static int	empty_buffer(char *buff, char **line, int i, int first)
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
			*line = ft_charcat(*line, buff[i]);
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

static void	end_line(char *buff, char **line, int i, int first_p)
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
				*line = ft_charcat(*line, buff[i]);
			buff[i] = -115;
		}
		else
		{
			buff[i] = -115;
			break ;
		}
	}
}

static int	check_cond(char *buff, char **line, int count, int *first_go)
{
	char	*cpybuff;
	char	*cpy;

	if ((ft_strchr(buff, (int)'\n')) == NULL && *first_go)
	{
		*line = ft_strncpy(*line, buff, count);
		first_go = 0;
	}
	else if ((ft_strchr(buff, (int)'\n')) == NULL)
	{
		cpybuff = (char *)ft_memalloc(sizeof(cpybuff) * (count + 1));
		cpybuff = ft_strncpy(cpybuff, buff, count);
		cpy = ft_strjoin(*line, cpybuff);
		free(*line);
		free(cpybuff);
		*line = cpy;
	}
	else if ((ft_strchr(buff, (int)'\n')) != NULL)
	{
		end_line(buff, line, (-1), *first_go);
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
	if ((nb = empty_buffer(buff, line, -1, 0)) == 1)
		return (1);
	else
		first_p = 0;
	while ((count = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if ((check_cond(buff, line, count, &first_p)) == 1)
			return (1);
		end_line(buff, line, (-1), (-1));
	}
	if (count == -1)
		return (-1);
	if (nb == 2 || **line)
		return (1);
	return (0);
}
