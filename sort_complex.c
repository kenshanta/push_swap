/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziental <jziental@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 17:17:03 by jziental          #+#    #+#             */
/*   Updated: 2026/09/14 16:58:07 by jziental         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	radix_num(t_stacks *toolbox)
{
	int	length;
	int	max_num;

	max_num = 0;
	length = stack_length(toolbox->a);
	while (length)
	{
		max_num++;
		length /= 2;
	}
	return (max_num);
}

void	complex_sort(t_stacks *toolbox)
{
	int	i;
	int	num_of_bits;
	int length;

	i = 0;
	num_of_bits = radix_num(toolbox);
	while (i < num_of_bits)
	{
		length = stack_length(toolbox->a);
		while (length)
		{
			if ((toolbox->a->index >> i & 1) == 0)
				pb(toolbox);
			else
				ra(toolbox);
			length--;
		}
		while (toolbox->b)
			pa(toolbox);
		i++;
	}
}
