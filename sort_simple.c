/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziental <jziental@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 18:11:17 by jziental          #+#    #+#             */
/*   Updated: 2026/09/18 21:53:34 by jziental         ###   ########.fr       */
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
static void	bigger_sort(t_stacks *toolbox)
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

static void	three_nums_sort(t_stacks *toolbox, int min_index)
{
	int	first;
	int	second;
	int	third;

	first = toolbox->a->index - min_index;
	second = toolbox->a->next->index - min_index;
	third = toolbox->a->prev->index - min_index;
	if (first == 0 && second == 2 && third == 1) //021
	{
		sa(toolbox);
		ra(toolbox);
	}
	else if (first == 1 && second == 2 && third == 0) //120
		rra(toolbox);
	else if (first == 1 && second == 0 && third == 2) //102
		sa(toolbox);
	else if (first == 2 && second == 1 && third == 0) //210
	{
		sa(toolbox);
		rra(toolbox);
	}
	else if (first == 2 && second == 0 && third == 1) //201
		ra(toolbox);
}
void	five_nums_sort(t_stacks *toolbox, int len)
{
	int	min_index;
	int	moves_to_top;

	min_index = 0;
	while (len - 3)
	{
		moves_to_top = find_smallest(toolbox, min_index);
		if (moves_to_top <= len / 2 && moves_to_top)
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
		len--;
	}
	three_nums_sort(toolbox, min_index);
	pa(toolbox);
	pa(toolbox);
}

void	simple_sort(t_stacks *toolbox)
{
	int	len;

	len = stack_length(toolbox->a);
	if (len == 2)
		sa(toolbox);
	else if (len == 3)
		three_nums_sort(toolbox, 0);
	else if (len <= 5)
		five_nums_sort(toolbox, len);
	else
		bigger_sort(toolbox);
}
