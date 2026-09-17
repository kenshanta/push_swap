/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziental <jziental@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 16:18:37 by jziental          #+#    #+#             */
/*   Updated: 2026/09/06 19:50:47 by jziental         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stacks *toolbox)
{
	if (push(&toolbox->b, &toolbox->a))
	{
		write(1, "pa\n", 3);
		toolbox->c_pa += 1;
		toolbox->total_ops += 1;
	}
}

void	pb(t_stacks *toolbox)
{
	if (push(&toolbox->a, &toolbox->b))
	{
		write(1, "pb\n", 3);
		toolbox->c_pb += 1;
		toolbox->total_ops += 1;
	}
}

void	sa(t_stacks *toolbox)
{
	if (swap(&toolbox->a))
	{
		write(1, "sa\n", 3);
		toolbox->c_sa += 1;
		toolbox->total_ops += 1;
	}
}

void	sb(t_stacks *toolbox)
{
	if (swap(&toolbox->b))
	{
		write(1, "sb\n", 3);
		toolbox->c_sb += 1;
		toolbox->total_ops += 1;
	}
}

void	ss(t_stacks *toolbox)
{
	int	s1;
	int	s2;

	s1 = swap(&toolbox->a);
	s2 = swap(&toolbox->b);
	if (s1 || s2)
	{
		write(1, "ss\n", 3);
		toolbox->c_ss += 1;
		toolbox->total_ops += 1;
	}
}
