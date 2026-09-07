/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziental <jziental@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 19:18:38 by jziental          #+#    #+#             */
/*   Updated: 2026/09/05 16:05:11 by jziental         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	whitespaces(char *nptr)
{
	if (*nptr == ' ' || *nptr == '\f' || *nptr == '\n'
		|| *nptr == '\r' || *nptr == '\t' || *nptr == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	long long	num;
	long long	sign;

	i = 0;
	num = 0;
	sign = 1;
	while (whitespaces((char *) nptr + i))
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (ft_isdigit(nptr[i]))
		num = num * 10 + (nptr[i++] - '0');
	return (sign * num);
}
//#include <stdlib.h>
//#include <stdio.h>
//#include <limits.h>

//int	main(void)
//{
//	int i = 0;
//	printf("min=%d, max=%d\n", INT_MIN, INT_MAX);
//	char *s[] = {"   +2147483647", "2d", "\0", "  -  123", "-2147483648",
//				"002", "-2147483648", "0 02", "   --00002", "121232", "   -02", "",
//				 "    ", "--123", "abc", "999dx2", "003458", "999888777666555",
//				 "-+48","-", NULL};
//	while (s[i])
//	{
//		ft_printf("ft_atoi(%s) = %d\n", s[i], ft_atoi(s[i]));
//		printf("   atoi(%s) = %d\n", s[i], atoi(s[i]));
//		i++;
//	}
//	return (0);
//}
