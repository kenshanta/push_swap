/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skovlekj <skovlekj@student.42warsaw.pl>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-09-11 19:32:15 by skovlekj          #+#    #+#             */
/*   Updated: 2026-09-11 19:32:15 by skovlekj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	ft_sqrt(int nb)
{
	float	sqrt;
    float temp;
    int i;

	if (nb < 0 || !nb)
        return (0);
    i = 0;
    sqrt = nb / 2.0f;
    while (i < 10)
    {
        temp = sqrt;
        sqrt = (temp + nb / temp) / 2.0f;
        if(temp == sqrt)
            break;
        i++;
    }
   return((int)sqrt);
}

static int	get_chunk_size(int	stack_length)
{
	if (stack_length <= 20)
		return (4);
	else if (stack_length <= 100)
		return (16);
	else if (stack_length <= 500)
		return (32);
	else
		return (ft_sqrt(stack_length));
}

static int get_max_pos(t_list *b)
{
	int	i;
	int	max_idx;
	int	max_pos;
	t_list	*head;

	head = b;
	max_idx = b->index;
	max_pos = 0;
	i = 0;
	while (1)
	{
		if (b->index > max_idx)
		{
			max_idx = b->index;
			max_pos = i;
		}
		b = b->next;
		i++;
		if (b == head)
			break;
	}
	return(max_pos);
}

static void push_b_to_a(t_stacks *toolbox)
{
	int	max_pos;
	int	size;

	while (toolbox->b)
	{
		max_pos = get_max_pos(toolbox->b);
		size = stack_length(toolbox->b);
		if (max_pos <= size /2)
		{
			while (max_pos--)
				rb(toolbox);
		}
		else
		{
			size = size - max_pos;
			while (size--)
				rrb(toolbox);
		}
		pa(toolbox);
	}
}

void    medium_sort(t_stacks *toolbox)
{
    int chunk_size;
    int chunk_max_range;
	int counter;
	int total_length;

	total_length = stack_length(toolbox->a);
	chunk_size = get_chunk_size(total_length);
    chunk_max_range = chunk_size;
	counter = 0;
    while (toolbox->a)
    {
		if(toolbox->a->index < chunk_max_range)
		{
			pb(toolbox);
			if (toolbox->b->index < chunk_max_range - (chunk_size / 2))
				rb(toolbox);
			counter++;
		}
		else
			ra(toolbox);
		if (counter == chunk_size)
		{
        	chunk_max_range += chunk_size;
			counter = 0;
			if (total_length - (chunk_max_range - chunk_size) < chunk_size)
				chunk_max_range = total_length;
		}
    }
    push_b_to_a(toolbox);
}
