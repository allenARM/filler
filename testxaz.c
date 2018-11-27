int		main(void)
{
	t_triler *filer;

	filer = malloc(sizeof(t_triler));
	initfiler(filer);
	if (getplayer(filer))
		return (1);
	while (1)
	{
		if (readmap(0, filer) != 0)
			return (1);
		free(filer->line);
		if (getpiece(0, filer) != 0)
			return (1);
		if (checkoptions(filer) == 1)
			return (1);
		clearmap(filer);
	}
	return (0);
}

int		getmapinfo(t_triler *fil)
{
	char *temcp;

	if (getlinija(0, fil))
		fil->temp = ft_strdup(fil->line);
	if ((temcp = ft_strchr(fil->temp, ' ')) == NULL)
		return (-1);
	*temcp = '\0';
	temcp++;
	if (ft_strcmp(fil->temp, "Plateau") != 0)
		return (-1);
	fil->height = ft_atoi(temcp);
	temcp = ft_strchr(temcp, ' ');
	fil->length = ft_atoi(temcp);
	free(fil->temp);
	fil->temp = NULL;
	if (!(getlinija(0, fil)))
		return (-1);
	return (0);
}

int		readmap(int filedesc, t_triler *filer)
{
	int i;

	i = 0;
	filer->line = ft_strdup("");
	if (getmapinfo(filer) != 0)
		return (-1);
	free(filer->line);
	filer->line = ft_strdup("");
	filer->map = malloc(sizeof(char *) * (filer->height));
	while (i < (long)filer->height)
		if (getlinija(filedesc, filer))
		{
			if ((filer->temp = ft_strchr(filer->line, ' ')) == NULL
				|| ft_isdigit(*(--filer->temp)) == 0)
				return (-1);
			filer->map[i++] = ft_strdup(ft_strchr(filer->line, ' ') + 1);
			free(filer->line);
			filer->line = ft_strdup("");
		}
	return (0);
}

int		getplayer(t_triler *filer)
{
	char *temp;

	if (getlinija(0, filer) != 1)
		return (-1);
	if ((temp = ft_strchr(filer->line, 'p')) == NULL)
		return (-1);
	if (ft_isdigit(*(++temp)) == 0)
		return (-1);
	if (*temp == '1' && ft_strstr(filer->line, "jguleski"))
	{
		filer->mychar = 'O';
		filer->enchar = 'X';
	}
	else if (*temp == '2' && ft_strstr(filer->line, "jguleski"))
	{
		filer->mychar = 'X';
		filer->enchar = 'O';
	}
	free(filer->line);
	if (filer->mychar == 'a')
		return (-1);
	return (0);
}
