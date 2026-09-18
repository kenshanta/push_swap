/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skovlekj <skovlekj@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 16:19:19 by jziental          #+#    #+#             */
/*   Updated: 2026/09/17 23:27:09 by skovlekj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stacks *toolbox)
{
	if (rev_rotate(&toolbox->a))
	{
		write(1, "rra\n", 4);
		toolbox->c_rra += 1;
		toolbox->total_ops += 1;
	}
}
void	rrb(t_stacks *toolbox)
{
	if (rev_rotate(&toolbox->b))
	{
		write(1, "rrb\n", 4);
		toolbox->c_rrb += 1;
		toolbox->total_ops += 1;
	}
}
void	rrr(t_stacks *toolbox)
{
	int	r1;
	int	r2;

	r1 = rev_rotate(&toolbox->a);
	r2 = rev_rotate(&toolbox->b);
	if (r1 || r2)
	{
		write(1, "rrr\n", 3);
		toolbox->c_rrr += 1;
		toolbox->total_ops += 1;
	}
}
