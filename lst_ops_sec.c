/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_ops_sec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziental <jziental@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 20:19:56 by jziental          #+#    #+#             */
/*   Updated: 2026/09/09 16:55:23 by jziental         ###   ########.fr       */
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

void	ft_toolsfree(t_stacks **stacks)
{
	if (!stacks || !*stacks)
		return ;
	if ((*stacks)->a)
		ft_lstclear(&(*stacks)->a);
	if ((*stacks)->b)
		ft_lstclear(&(*stacks)->b);
	free(*stacks);
	*stacks = NULL;
}

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;
	t_list	*node;

	node = *lst;
	tmp = NULL;
	if (!lst || !*lst)
		return ;
	(*lst)->prev->next = NULL;
	while (node)
	{
		if (node->next)
			tmp = node->next;
		else
			tmp = NULL;
		if (node->num != 0)
			node->num = 0;
		if (node->index != 0)
			node->index = 0;
		free(node);
		node = tmp;
	}
	*lst = NULL;
}
