/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <redei-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:47:43 by vcastald          #+#    #+#             */
/*   Updated: 2024/11/29 16:12:30 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	n;

	n = 0;
	while (*str != '\0')
	{
		n++;
		str++;
	}
	return (n);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	res;

	i = 0;
	j = 0;
	res = 0;
	while (dest[i])
		i++;
	while (src[res])
		res++;
	if (size <= i)
		res += size;
	else
		res += i;
	while (src[j] && (i + 1) < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (res);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	unsigned int	i;	

	i = 0;
	if (n == 0)
		return (ft_strlen(src));
	while (i < n - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s)
{
	int		n;
	char	*dest;

	n = ft_strlen(s);
	dest = (char *)malloc((n + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, s, n + 1);
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l1;
	int		size;
	char	*dest;

	l1 = ft_strlen(s1);
	size = l1 + ft_strlen(s2) + 1;
	dest = (char *)malloc(size * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1, size);
	ft_strlcat(dest, s2, size);
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	size;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	substr = (char *)ft_calloc((len + 1), sizeof(char));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dest;
	int		i;
	unsigned char	*tmp;

	i = 0;
	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	if (nmemb > INT_MAX / size)
		return (NULL);
	i = nmemb * size;
	dest = malloc(i);
	tmp = (unsigned char *)dest;
	if (dest == NULL)
		return (NULL);
	while(size --)
	{
		*tmp = '\0';
		tmp++;
	}
	return (tmp);
}
