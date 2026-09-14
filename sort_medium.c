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

// static  divide_into_chunks()
// {

// }
static int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	if (nb < 0)
		return (0);
	while (i < nb / i)
        i++;
    if (i == nb / i)
        return (i);
	else
		return (0);
}

void    medium_sort(t_stacks *toolbox)
{
    int stack_len;
    int chunk_size;
    int chunk_max_range;
    int count;

    stack_len = 0;
    if (toolbox->a)
        stack_len = stack_length(toolbox->a);
    chunk_size = ft_sqrt(stack_len);
    chunk_max_range = ft_sqrt(stack_len);
    while (stack_len > 0)
    {
        count = chunk_size;
        while(count)
        {
            if(toolbox->a->index <= chunk_max_range)
            {
                pb(toolbox);
                if (toolbox->a->index <= chunk_max_range / 2)
                    rb(toolbox);                
                count--;
            }
            else
                ra(toolbox);
        }
        ft_printf("current b index: %i\n", toolbox->b->index);
        chunk_max_range += chunk_size;
        stack_len -= chunk_size;
    }
    while (toolbox->b)
    {
        pa(toolbox);
        ft_printf("current value stack a: %i\n", toolbox->a->num);
    }
}