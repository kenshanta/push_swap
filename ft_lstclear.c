/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziental <jziental@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 17:30:55 by jziental          #+#    #+#             */
/*   Updated: 2026/09/06 17:49:26 by jziental         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
