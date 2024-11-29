/* char	*find_char(const char *s, int c)
{
	
} */

char	*clean_line(char *str)
{
	int		i;
	char	*tmp;

	// i = 0;
	// len = ft_strlen(str);
	while (str[i] && str[i] != '\n')
		i++;
	// if (str[i] == '\n')
	//  	i++;
	if (!str[i])
		return (NULL);
	tmp = ft_strdup(str + i + 1);
	free(str);
	return (tmp);
}

char	*append_line(char *start)
{
	int		i;
	char	*ret;
	// char	*tmp;
	
	i = 0;
	// ret = ft_strdup("");
	// tmp = ft_strdup(start);
	while (tmp[i] != '\n' && tmp[i])
		i++;
	ret = (char *)malloc((i + 2) * sizeof(char));
	// tmp[i + 1] = '\0';
	// ret = ft_strjoin(ret, tmp);
	// free(tmp);
	ft_strlcpy(ret, start, i + 2);
	return (ret);
}

char	*read_line(char *s, int fd)
{
	size_t	bytes_read;
	char	*buff;
	char	*tmp;

	// buff = ft_strdup("");
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	bytes_read = read(fd, buff, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(buff);
		return (line);
	}
	ft_strlcat(s, buff, ft_strlen(s) + ft_strlen(buff) + 1);
	free(buff);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*fin;
	int 		i;
	int			flag;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strdup("");
	fin = ft_strdup("");
	flag = 0;
	while (flag != 1)
	{
		line = read_line(line, fd);
		while (line)
		{
			if(line[i] == '\n')
			{
				ft_strlcat(fin, line, i + 1);
				flag = 1;
				break;
			}
		//ft_strlcat(line, read_line(line, fd), BUFFER_SIZE);
		i++;
		}
		line = clean_line(line);
	}
	// se non trovo il set devo fare un altro reed e rifarare il ciclo
	//fin = append_line(line);
	
	return (fin);
}
