/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziental <jziental@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 20:19:56 by jziental          #+#    #+#             */
/*   Updated: 2026/09/05 13:37:39 by jziental         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **stack, t_list *new)
{
	t_list	*last;
	t_list	*head;

	if (!stack || !new)
		return ;
	head = *stack;
	if (!*stack || !head)
	{
		*stack = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	last = ft_lstlast(*stack);
	last->next = new;
	new->next = head;
	new->prev = last;
	head->prev = new;
}
