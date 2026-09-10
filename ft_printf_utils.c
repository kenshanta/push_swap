/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziental <jziental@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 18:59:53 by jziental          #+#    #+#             */
/*   Updated: 2026/08/21 16:41:18 by jziental         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putstr(char *s)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	if (!s)
	{
		if (write(1, "(null)", 6) < 0)
			return (-1);
		return (6);
	}
	while (*(s + i))
	{
		if (ft_putchar(*(s + i)) < 0)
			return (-1);
		count++;
		i++;
	}
	return (count);
}

int	ft_putint(int c)
{
	int	count;

	count = 0;
	if (c == -2147483648)
	{
		count += ft_putstr("-2147483648");
		return (count);
	}
	if (c < 0)
	{
		count += ft_putchar('-');
		c = -c;
		if (c >= 10)
			count += ft_putint(c / 10);
		count += ft_putchar(c % 10 + '0');
	}
	else if (c < 10)
		count += ft_putchar(c % 10 + '0');
	else
	{
		count += ft_putint(c / 10);
		count += ft_putchar(c % 10 + '0');
	}
	return (count);
}

int	ft_putuint(unsigned int i)
{
	int	count;

	count = 0;
	if (i < 10)
		count += ft_putchar(i + '0');
	else
	{
		count += ft_putuint(i / 10);
		count += ft_putchar(i % 10 + '0');
	}
	return (count);
}

int	ft_puthex(unsigned long long i, char x)
{
	int		count;
	char	*base;

	count = 0;
	if (x == 'x')
		base = "0123456789abcdef";
	else if (x == 'X')
		base = "0123456789ABCDEF";
	if (i < 16)
		count += ft_putchar(base[i % 16]);
	else
	{
		count += ft_puthex(i / 16, x);
		count += ft_putchar(base[i % 16]);
	}
	return (count);
}

int	ft_putptr(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		count += ft_putstr("(nil)");
	else
	{
		count += ft_putstr("0x");
		count += ft_puthex((unsigned long long)ptr, 'x');
	}
	return (count);
}
