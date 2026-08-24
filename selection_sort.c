/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziental <jziental@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 17:12:07 by jziental          #+#    #+#             */
/*   Updated: 2026/08/17 18:57:01 by jziental         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Sorts the array in ascending order and returns the same pointer.
int	*ft_selection(int *set, int length)
{
	int	i;
	int	j;
	int	min_index;
	int	tmp;

	i = 0;
	while (i < length - 1)
	{
		min_index = i;
		j = i + 1;
		while (j < length)
		{
			if (set[j] < set[min_index])
				min_index = j;
			j++;
		}
		tmp = set[i];
		set[i] = set[min_index];
		set[min_index] = tmp;
		i++;
	}
	return (set);
}

#include <stdio.h>

int main()
{
	int	set[] = {3, 2, 1, 11, 34, 123, 0, -7};
	int	len = sizeof(set) / sizeof(set[0]);
	int	i = 0;

	ft_selection(set, len);
	while (i < len)
	{
		printf("%d ", set[i]);
		i++;
	}

	return (0);
}
