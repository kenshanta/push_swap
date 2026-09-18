/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziental <jziental@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 17:12:07 by jziental          #+#    #+#             */
/*   Updated: 2026/09/13 17:10:43 by jziental         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	*make_set(t_stacks **toolbox)
{
	t_list	*current;
	int		*set;
	int		length;
	int		i;

	if (!toolbox || !(*toolbox)->a)
		return (ft_exit(toolbox, 1), NULL);
	length = stack_length((*toolbox)->a);
	set = malloc(sizeof(int) * length);
	if (!set)
		return (ft_exit(toolbox, 1), NULL);
	i = 0;
	current = (*toolbox)->a;
	while (i < length)
	{
		set[i++] = current->num;
		current = current->next;
	}
	return (set);
}

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
