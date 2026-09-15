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
        count = 0;
        while(stack_len > 0 && count < stack_len)
        {
            if(toolbox->a->index < chunk_max_range)
            {
                int idx = toolbox->a->index;
                pb(toolbox);
                if (idx > chunk_max_range / 2)
                    rb(toolbox);
                stack_len--;
            }
            else
            {
                ra(toolbox);
                count++;
            }
        }
        // ft_printf("current b index: %i\n", toolbox->b->index);
        chunk_max_range += chunk_size;
    }
    while (toolbox->b)
    {
        pa(toolbox);
        // ft_printf("current value stack a: %i\n", toolbox->a->num);
    }
}