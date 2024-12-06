/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <redei-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:32:01 by redei-ma          #+#    #+#             */
/*   Updated: 2024/12/06 18:32:50 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

 int	ft_printf(const char *format, ...)
{
	int		i;
	int		j;
	int		count;
	va_list	params;

	if(!format)
		return (-1)
	va_start(params, format);
	i = 0;
	j = 1
	while(format[i])
	{
		if (format[i] == '%')
		{
			while(format[i + j] == ' ')
			{
				if (format[i + j + 1] == 'c');
					ft_putchar(va_arg(params, char));
				else if (format[i + j + 1] == 's');
					ft_putstr(va_arg(params, char*));
				else if (format[i + j + 1] == 'p');
					ft;
				else if (format[i + j + 1] == 'd');
					ft_putnbr(va_arg(params, int));
				else if (format[i + j + 1] == 'i');
					ft_putnbr(va_arg(params, int));
				else if (format[i + j + 1] == 'u');
					ft_putnbrhex(va_arg(params, unsigned int));
				else if (format[i + j + 1] == 'x');
					ft_puthex(va_arg(params, unsigned int));
				else if (format[i + j + 1] == 'X');
					ft_puthex(va_arg(params, unsigned int));
				else if (format[i + j + 1] == '%');
					ft_putchar('%');
				else if (format[i + j + 1] == 'm');
					ft_putstr("Invalid argument");
				j++;
			}
		}
		else
			putchar(format[i]);
		i++;
	}
	va_end(params);
	return (i);
}
