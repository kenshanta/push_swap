/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziental <jziental@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 19:07:43 by jziental          #+#    #+#             */
/*   Updated: 2026/09/18 16:50:57 by jziental         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	compute_disorder(t_stacks **toolbox, t_list *a)
{
	t_list	*i;
	t_list	*j;

	i = a;
	while (i->next != a)
	{
		j = i->next;
		while (j != a)
		{
			(*toolbox)->pairs += 1;
			if (i->num > j->num)
				(*toolbox)->mistakes += 1;
			else if (i->num == j->num)
				ft_exit(toolbox, 1);
			j = j->next;
		}
		i = i->next;
	}
}
