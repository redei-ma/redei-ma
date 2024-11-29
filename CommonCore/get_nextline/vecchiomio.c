int	find_newline(str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buff;
	char		*final;
	int			k;
// devo cercare \n anche prima perche potrebbe esserci negli scarti e non serve aprire
	k = ft_strlen(line);
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (read(fd, buff, BUFFER_SIZE) > 0)
	{
		ft_strjoin(line, buff, ft_strlen(line) + BUFFER_SIZE + 1)
		if (find_newline(line) <= len_line)
			final = ft_substr(line, 0, find_newline(line)); //sottostringa da restituire fino a \n
			line = ft_strdup(line + find_newline(line) + 1); //stringa accorciata fino al puinto di \n
			break;
	}
	free (buff);
	return (final);
}