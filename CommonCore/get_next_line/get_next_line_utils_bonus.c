/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <redei-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:38:08 by redei-ma          #+#    #+#             */
/*   Updated: 2024/12/03 16:42:10 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *src)
{
	char		*dest;
	size_t		len;

	len = ft_strlen(src);
	dest = (char *)ft_calloc(len + 1, sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_strlcat(dest, src, len);
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
	ft_strlcat(substr, s + start, len + 1);
	return (substr);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*dest;
	unsigned char	*tmp;
	size_t			tot;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	tot = nmemb * size;
	if (tot / size != nmemb)
		return (NULL);
	dest = malloc(tot);
	if (dest == NULL)
		return (NULL);
	tmp = (unsigned char *)dest;
	while (tot--)
	{
		*tmp = 0;
		tmp++;
	}
	return (dest);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	d_len;
	size_t	s_len;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	if (size <= d_len)
		return (size + s_len);
	else
	{
		i = 0;
		while (src[i] != '\0' && (d_len + i) < size - 1)
		{
			dst[d_len + i] = src[i];
			i++;
		}
		dst[d_len + i] = '\0';
		return (d_len + s_len);
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len_s1;
	unsigned int	len;
	char			*dest;

	len_s1 = ft_strlen(s1);
	len = len_s1 + ft_strlen(s2) + 1;
	dest = ft_calloc(len, 1);
	if (!dest)
		return (NULL);
	ft_strlcat(dest, s1, len_s1 + 1);
	ft_strlcat(dest, s2, len);
	return (dest);
}
