/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziental <jziental@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 16:19:06 by jziental          #+#    #+#             */
/*   Updated: 2026/09/06 19:51:16 by jziental         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stacks *toolbox)
{
	if (rotate(&toolbox->a))
	{
		write(1, "ra\n", 3);
		toolbox->c_ra += 1;
		toolbox->total_ops += 1;
	}
}

void	rb(t_stacks *toolbox)
{
	if (rotate(&toolbox->b))
	{
		write(1, "rb\n", 3);
		toolbox->c_rb += 1;
		toolbox->total_ops += 1;
	}
}

void	rr(t_stacks *toolbox)
{
	int	r1;
	int	r2;

	r1 = rotate(&toolbox->a);
	r2 = rotate(&toolbox->b);
	if (r1 || r2)
	{
		write(1, "rr\n", 3);
		toolbox->c_rr += 1;
		toolbox->total_ops += 1;
	}
}
