/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <redei-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:18:23 by lacerbi           #+#    #+#             */
/*   Updated: 2024/12/06 18:43:34 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putstr(char *s, int fd)
{
	size_t	i;

	i = ft_strlen(s);
	if (!s || fd < 0)
		return (0);
	write(1, s, i);
	return(i);
}