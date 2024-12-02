/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <redei-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:47:13 by redei-ma          #+#    #+#             */
/*   Updated: 2024/11/27 19:51:42 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_words(const char *s, char c)
{
	int	count;
	int	flag;

	count = 0;
	flag = 0;
	while (s && *s != '\0')
	{
		if (*s == c)
			flag = 0;
		else if (flag == 0)
		{
			count++;
			flag = 1;
		}
		s++;
	}
	return (count);
}

void	ft_cleanmat(char **dest)
{
	char	**tmp;

	tmp = dest;
	while (*tmp)
	{
		free(*tmp);
		*tmp = NULL;
		tmp++;
	}
	free(dest);
}

void	**ft_allocate(char **dest, const char *s, const char c)
{
	char	**start;
	int		n;

	start = dest;
	while (*s)
	{
		while (*s == c)
			s++;
		n = 0;
		while (s[n] != c && s[n] != '\0')
			n++;
		if (n > 0)
		{
			*dest = ft_substr(s, 0, n);
			if(!*dest)
			{
				ft_cleanmat(start);
				return ;
			}
			dest++;
		}
		s += n;
	}
}

char	**ft_split(char const *s, char c)
{
	char		**dest;
	size_t		words;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	dest = (char **)ft_calloc(words + 1, sizeof(char *));
	if (!dest)
		return (NULL);
	ft_allocate(dest, s, c);
	return (dest);
}

/* int	main()
{
	char	str[] = "zhello!zzzzzzzz";
	char	c = 'z';
	char	**dest = ft_split(str, c);

	int	i = 0;
	while (dest[i] != NULL)
	{
		printf("%s\n", dest[i]);
		free(dest[i]);
        i++;
	}
	free(dest);
} */