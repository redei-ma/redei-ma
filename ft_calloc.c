/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <redei-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:56:34 by redei-ma          #+#    #+#             */
/*   Updated: 2024/11/29 12:17:34 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dest;
	int		tot;

	tot = nmemb * size;
	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	if (tot / size != nmemb)
		return (NULL);
	dest = malloc(tot);
	if (dest == NULL)
		return (NULL);
	ft_bzero(dest, tot);
	return (dest);
}

/* int     main(int argc, char *argv[])
{
    char    *s1;
    char    *s2;
    size_t	i = ft_atoi(argv[1]) * ft_atoi(argv[2]);     
	if (argc != 3)
            return(1);
    s1 = calloc(ft_atoi(argv[1]), ft_atoi(argv[2]));
	printf("Funzione originale: %p\n", s1);
    s2 = ft_calloc(ft_atoi(argv[1]), ft_atoi(argv[2]));
    printf("Funzione ricreata: %p\n", s2);
	printf("%zu", i);
    return (0);
} */