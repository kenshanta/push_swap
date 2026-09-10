/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_general.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziental <jziental@test42.pl>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-09-05 19:36:31 by jziental          #+#    #+#             */
/*   Updated: 2026-09-05 19:36:31 by jziental         ###   ########.pl       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_list **stack)
{
	if (stack && *stack && (*stack)->next != *stack)
	{
		*stack = (*stack)->next;
		return (1);
	}
	return (0);
}

int	rev_rotate(t_list **stack)
{
	if (stack && *stack && (*stack)->next != *stack)
	{
		*stack = (*stack)->prev;
		return (1);
	}
	return (0);
}

int	swap(t_list **stack)
{
	int	temp_num;
	int temp_index;

	if (stack && (*stack) && (*stack)->next != (*stack))
	{
		temp_num = (*stack)->num;
		(*stack)->num = (*stack)->next->num;
		(*stack)->next->num = temp_num;
		temp_index = (*stack)->index;
		(*stack)->index = (*stack)->next->index;
		(*stack)->next->index = temp_index;
		return (1);
	}
	return (0);
}
int	push(t_list **source, t_list **dest)
{
	t_list	*node;

	if (source && *source)
		{
			node = *source;
			if (node->next == node)
				*source = NULL;
			else
			{
				node->prev->next = node->next;
				node->next->prev = node->prev;
				*source = node->next;
			}
			node->next = node;
			node->prev = node;
			ft_lstadd_front(dest, node);
			return (1);
		}
		return (0);
}
