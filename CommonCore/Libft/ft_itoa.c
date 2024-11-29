/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:47:26 by redei-ma          #+#    #+#             */
/*   Updated: 2024/11/25 17:47:29 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_let(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*dest;
	int		len;
	long	nb;

	nb = n;
	len = ft_count_let(n);
	dest = (char *)ft_calloc((len + 1), sizeof(char));
	if (!dest)
		return (NULL);
	if (nb < 0)
	{
		dest[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		dest[0] = '0';
	while (nb != 0)
	{
		dest[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (dest);
}

/* int main ()
{
	int n = -2147483648;
	char *arr = ft_itoa(n);
	printf("%s", arr);
	return 0;
} */