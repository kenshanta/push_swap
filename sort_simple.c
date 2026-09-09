/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziental <jziental@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 18:11:17 by jziental          #+#    #+#             */
/*   Updated: 2026/09/09 20:22:22 by jziental         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_position (t_stacks *toolbox, int smallest_index)
{
	int		count;
	t_list	*current;

	count = 0;
	current = toolbox->a;
	while (current->next = toolbox->a)
	{
		if (current->index == smallest_index)
			break;
		current = current->next;
		count++;
	}
	return (count);
}

void simple_sort (t_stacks *toolbox)
{
	int		smallest;
	int		length;
	int		moves_to_top;
	t_list	*current;

	smallest = 0;
	length = stack_length(toolbox->a);
	current = toolbox->a;
	while(current)
	{
		while (moves_to_top)
		{
			moves_to_top = find_min_position(current, smallest);
			if (moves_to_top <= length / 2 && moves_to_top)
				ra(toolbox);
			else if (moves_to_top > length / 2)
				rra(toolbox);
		}
		pb(toolbox);
		smallest++;
		current = current->next;
	}
}
