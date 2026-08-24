/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziental <jziental@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 20:40:19 by jziental          #+#    #+#             */
/*   Updated: 2026/08/21 16:41:28 by jziental         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	size_t	i;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count += ft_parse(args, (format[i + 1]));
			i += 2;
		}
		else if (format[i] == '%' && !format[i + 1])
			return (-1);
		else
		{
			count += ft_putchar(format[i]);
			i++;
		}
	}
	va_end(args);
	return (count);
}

int	ft_parse(va_list args, char format)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (format == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		count += ft_putptr(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		count += ft_putint(va_arg(args, int));
	else if (format == 'u')
		count += ft_putuint(va_arg(args, unsigned int));
	else if (format == 'X' || format == 'x')
		count += ft_puthex(va_arg(args, unsigned int), format);
	else if (format == '%')
		count += ft_putchar('%');
	else
		return (-1);
	return (count);
}
//Auxiliary test main() in README
#include <stdio.h>
int main()
{
	ft_printf("%u\n", -1);
	printf("%u\n", -1);
	return (-1);
}
