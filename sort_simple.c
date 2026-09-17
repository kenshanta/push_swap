/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziental <jziental@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 18:11:17 by jziental          #+#    #+#             */
/*   Updated: 2026/09/12 14:28:22 by jziental         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_smallest(t_stacks *toolbox, int index)
{
	int		position;
	int		length;
	t_list	*current;

	if (!toolbox)
		return (0);
	length = stack_length(toolbox->a);
	position = 0;
	current = toolbox->a;
	while (length)
	{
		if (current->index == index)
			break ;
		current = current->next;
		position++;
		length--;
	}
	return (position);
}

void	simple_sort(t_stacks *toolbox)
{
	int	min_index;
	int	length;
	int	moves_to_top;

	min_index = 0;
	length = stack_length(toolbox->a);
	while (length)
	{
		moves_to_top = find_smallest(toolbox, min_index);
		if (moves_to_top <= length / 2 && moves_to_top)
		{
			while (toolbox->a->index != min_index)
				ra(toolbox);
		}
		else if (moves_to_top)
		{
			while (toolbox->a->index != min_index)
				rra(toolbox);
		}
		pb(toolbox);
		min_index++;
		length--;
	}
	while (toolbox->b)
		pa(toolbox);
}
