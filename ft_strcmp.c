/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziental <jziental@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 19:11:47 by jziental          #+#    #+#             */
/*   Updated: 2026/08/26 17:50:20 by jziental         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
//#include <string.h>
//#include <stdio.h>
//int main()
//{
//	char s1[] = "";
//	char s2[] = "";
//	printf ("%d\n", strncmp(s1,s2, 1));
//	printf ("%d\n\n", ft_strncmp(s1,s2, 1));

//	char s3[] = "a";
//	char s4[] = "";
//	printf ("%d\n", strncmp(s3,s4, 1));
//	printf ("%d\n\n", ft_strncmp(s3,s4, 1));

//	char s5[] = "";
//	char s6[] = "a";
//	printf ("%d\n", strncmp(s5,s6, 0));
//	printf ("%d\n\n", ft_strncmp(s5,s6, 0));

//	char s7[] = "ab";
//	char s8[] = "abc";
//	printf ("%d\n", strncmp(s7,s8, 0));
//	printf ("%d\n\n", ft_strncmp(s7,s8, 0));

//	char s9[] = "ac";
//	char s10[] = "aba";
//	printf ("%d\n", strncmp(s9,s10, 3));
//	printf ("%d\n\n", ft_strncmp(s9,s10, 3));

//	char s11[] = "ab";
//	char s12[] = "aca";
//	printf ("%d\n", strncmp(s11,s12, 3));
//	printf ("%d\n\n", ft_strncmp(s11,s12, 3));

//	char s13[] = "test\200";
//	char s14[] = "test\0";
//	printf ("%d\n", strncmp(s13,s14, 6));
//	printf ("%d\n\n", ft_strncmp(s13,s14, 6));

//	char s15[] = "abcdefgh";
//	char s16[] = "abcdwxyz";
//	printf ("%d\n", strncmp(s15,s16, 4));
//	printf ("%d\n\n", ft_strncmp(s15,s16, 4));

//	char s17[] = "lorem ipsum dolor sit amet";
//	char s18[] = "ipsum";
//	printf ("%d\n", strncmp(s17 + 6,s18, 5));
//	printf ("%d\n\n", ft_strncmp(s17 + 6,s18, 5));

//	return (0);
//}
