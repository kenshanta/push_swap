/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziental <jziental@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 19:42:32 by jziental          #+#    #+#             */
/*   Updated: 2026/09/09 16:53:56 by jziental         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*lstnew;

	lstnew = (t_list *)malloc(sizeof(t_list));
	if (lstnew == NULL)
		return (NULL);
	lstnew->num = content;
	lstnew->index = 0;
	lstnew->next = NULL;
	lstnew->prev = NULL;
	return (lstnew);
}
int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*tmp;

	size = 0;
	tmp = NULL;
	if (lst)
	{
		size = 1;
		tmp = lst->next;
		while (tmp != lst)
		{
			size++;
			lst = lst->next;
			tmp = lst;
		}
	}
	return (size);
}

t_list	*ft_lstlast(t_list *head)
{
	if (!head)
		return (head);
	return (head->prev);
}

void	ft_lstdelone(t_list **lst)
{
	if (!*lst)
		return ;
	if ((*lst)->next == *lst)
		*lst = NULL;
	else
	{
		(*lst)->prev->next = (*lst)->next;
		(*lst)->next->prev = (*lst)->prev;
	}
	free(*lst);
	*lst = NULL;
}
