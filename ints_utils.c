/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ints_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziental <jziental@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 19:18:38 by jziental          #+#    #+#             */
/*   Updated: 2026/09/11 17:29:36 by jziental         ###   ########.fr       */
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
	int			i;
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

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int	ft_onlydigits(char **str)
{
	int	i;
	int	j;

	j = 0;
	while (str[j])
	{
		i = 0;
		if (str[j][i] == '-' || str[j][i] == '+')
			i++;
		if (!str[j][i])
			return (0);
		while (str[j][i])
		{
			if (!ft_isdigit(str[j][i]))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	has_whitespaces(char *nptr)
{
	int	i;

	i = 0;
	while (nptr[i])
	{
		if (nptr[i] == ' ' || nptr[i] == '\f' || nptr[i] == '\n'
			|| nptr[i] == '\r' || nptr[i] == '\t' || nptr[i] == '\v')
			return (1);
		i++;
	}
	return (0);
}
//#include <stdio.h>
//int main() //int ziemniak, char	**ziemniaki
//{
////	if (ziemniak == 1 && ziemniaki)
////		printf("co?%s, ile?%d\n\n", ziemniaki[0], ziemniak);
//	char *args[4] = {"123", "567", "-", NULL};
//	printf("%i", ft_onlydigits(args));
//	return 0;
//}
//#include <stdlib.h>
//#include <stdio.h>
//#include <limits.h>

//int	main(void)
//{
//	int i = 0;
//	printf("min=%d, max=%d\n", INT_MIN, INT_MAX);
//	char *s[] = {"   +2147483647", "2d", "\0", "  -  123", "-2147483648",
//				"002", "-2147483648", "0 02", "   --00002",
// "121232", "   -02", "","    ", "--123", "abc", "999dx2", "003458",
// "999888777666555","-+48","-", NULL};
//	while (s[i])
//	{
//		ft_printf("ft_atoi(%s) = %d\n", s[i], ft_atoi(s[i]));
//		printf("   atoi(%s) = %d\n", s[i], atoi(s[i]));
//		i++;
//	}
//	return (0);
//}
