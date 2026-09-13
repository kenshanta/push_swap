/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziental <jziental@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 17:17:03 by jziental          #+#    #+#             */
/*   Updated: 2026/09/13 14:20:44 by jziental         ###   ########.fr       */
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
	int	num_of_digits;
	int length;

	i = 0;
	num_of_digits = radix_num(toolbox);
	while (i < num_of_digits - 1)
	{
		length = stack_length(toolbox);
		while (length)
		{
			if (toolbox->a->num >> i & 1)
				ra(toolbox);
			else
				pb(toolbox);
			length--;
		}
		i++;
	}
	while (toolbox->b)
		pa(toolbox);

}
