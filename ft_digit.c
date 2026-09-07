/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziental <jziental@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 20:25:38 by jziental          #+#    #+#             */
/*   Updated: 2026/09/06 17:48:59 by jziental         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	while(str[j])
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
//int	has_whitespaces(char *nptr)
//{
//	int	i;

//	i = 0;
//	while (nptr[i])
//	{
//		if (nptr[i] == ' ' || nptr[i] == '\f' || nptr[i] == '\n'
//		|| nptr[i] == '\r' || nptr[i] == '\t' || nptr[i] == '\v')
//			return (1);
//		i++;
//	}
//	return (0);
//}
#//include <stdio.h>
//int main() //int ziemniak, char	**ziemniaki
//{
////	if (ziemniak == 1 && ziemniaki)
////		printf("co?%s, ile?%d\n\n", ziemniaki[0], ziemniak);
//	char *args[4] = {"123", "567", "-", NULL};
//	printf("%i", ft_onlydigits(args));
//	return 0;
//}
