/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziental <jziental@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 17:12:07 by jziental          #+#    #+#             */
/*   Updated: 2026/09/12 15:11:41 by jziental         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// Sorts the array in ascending order and returns the same pointer.
static int	*ft_selection(int *set, int length)
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
//counts number of nodes in circular list
int	stack_length(t_list *stack)
{
	t_list *current;
	int	count;

	if (!stack)
		return (0);
	current = stack->next;
	count = 1;
	while (current != stack)
	{
		count++;
		current = current->next;
	}
	return (count);
}
//make copies values from stack to array set
static int	*make_set(t_stacks **toolbox)
{
	t_list	*current;
	int		*set;
	int		length;
	int		i;

	if (!toolbox || !(*toolbox)->a)
		return (ft_exit(toolbox), NULL);
	length = stack_length((*toolbox)->a);
	set = malloc(sizeof(int) * length);
	if (!set)
		return (ft_exit(toolbox), NULL);
	i = 0;
	current = (*toolbox)->a;
	while (i < length)
	{
		set[i++] = current->num;
		current = current->next;
	}
	return (set);
}
//assign indexes based on comparing nums in sorted array and stack a
void	assign_indexes(t_stacks **toolbox)
{
	t_list	*current;
	int		length;
	int		*set;
	int		i;

	if (!toolbox || !(*toolbox)->a)
		return ;
	length = stack_length((*toolbox)->a);
	set = ft_selection(make_set(toolbox), length);
	i = 0;
	current = (*toolbox)->a;
	while (i < length)
	{
		while (current->num != set[i])
			current = current->next;
		current->index = i++;
	}
	free(set);
}


//#include <stdio.h>

//int	main()
//{
//	int	set[] = {3, 2, 1, 11, 34, 123, 0, -7};
//	int	len = sizeof(set) / sizeof(set[0]);
//	int	i = 0;

//	ft_selection(set, len);
//	while (i < len)
//	{
//		printf("%d ", set[i]);
//		i++;
//	}

//	return (0);
//}
