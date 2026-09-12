/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziental <jziental@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 19:07:43 by jziental          #+#    #+#             */
/*   Updated: 2026/09/11 17:34:44 by jziental         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void compute_disorder(t_stacks **toolbox,  t_list *a)
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
				ft_exit(toolbox);
			j = j->next;
		}
		i = i->next;
	}
}
//int main()
//{
//	t_stacks *toolbox;
//	t_list	*node;
//	int		nums[] = {5, 3, 7, 6, -5, 0};
//	int		i = 0;

//	toolbox = stacks_init();
//	while (nums[i])
//	{
//		node = ft_lstnew(nums[i++]);
//		ft_lstadd_back(&toolbox->a, node);
//	}
//	compute_disorder(&toolbox, toolbox->a);
//	printf("%d/%d", toolbox->mistakes, toolbox->pairs);
//	ft_toolsfree(&toolbox);
//	return (0);
//}
