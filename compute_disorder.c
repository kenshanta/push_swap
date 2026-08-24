/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziental <jziental@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 19:07:43 by jziental          #+#    #+#             */
/*   Updated: 2026/08/21 16:45:51 by jziental         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

float compute_disorder(int *a, size_t size)
{
	float	mistakes;
	float	total_pairs;
	size_t	i;
	size_t	j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	j = 0;
	while (i < size - 1)
	{
		printf("i:%ld\n", i);
		j = i + 1;
		while (j < size - 1)
		{
			total_pairs += 1;
			printf("j:%ld, pairs:%f\n", j, total_pairs);
			if (a[i] > a[j])
				mistakes += 1;
			printf("%d>?%d\n", a[i], a[j]);
			printf("%f\n____________", mistakes);
			j++;
		}
		i++;
	}
return (mistakes / total_pairs);
}

int main()
{
	//int	i = 0;
	int set[] = {5, 2, 3, 1};
	size_t size = sizeof(set)/sizeof(set[0]);
	//int len = sizeof(set)/sizeof(set[0]);
	printf("\ndisorder = %f", compute_disorder(set, size));
	//while(i < len)
	//{
	//printf("", set[i]);
	//i++;
	//}
	return (0);
}
