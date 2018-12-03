/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 13:54:14 by amelikia          #+#    #+#             */
/*   Updated: 2018/10/19 14:49:28 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**checkforn(char **line, int fd, int len, char **str)
{
	char	*tmp;

	*line = ft_strsub(str[fd], 0, len);
	tmp = ft_strdup(str[fd] + len + 1);
	free(str[fd]);
	str[fd] = tmp;
	return (str);
}

static int		newline(char **str, char **line, int fd, int vlu)
{
	int		len;

	len = 0;
	while (str[fd][len] != '\n' && str[fd][len] != '\0')
		len++;
	if (str[fd][len] == '\n')
		checkforn(line, fd, len, str);
	else if (str[fd][len] == '\0')
	{
		if (vlu == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*str[255];
	char		buffer[BUFF_SIZE + 1];
	char		*tmp;
	int			vlu;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((vlu = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[vlu] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strnew(1);
		tmp = ft_strjoin(str[fd], buffer);
		free(str[fd]);
		str[fd] = tmp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (vlu < 0)
		return (-1);
	else if (vlu == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
		return (0);
	return (newline(str, line, fd, vlu));
}
