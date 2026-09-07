/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziental <jziental@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 18:43:36 by jziental          #+#    #+#             */
/*   Updated: 2026/09/06 19:53:15 by jziental         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	ft_lstadd_front(t_list **stack, t_list *new)
{
	t_list	*head;
	t_list	*last;

	if (!stack || !new)
		return ;
	head = *stack;
	if (!head)
	{
		*stack = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	last = ft_lstlast(*stack);
	last->next = new;
	new->prev = last;
	new->next = head;
	head->prev = new;
	*stack = new;
}

