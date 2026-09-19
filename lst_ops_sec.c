/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziental <jziental@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 19:42:32 by jziental          #+#    #+#             */
/*   Updated: 2026/09/18 17:03:29 by jziental         ###   ########.fr       */
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

t_list	*ft_lstlast(t_list *head)
{
	if (!head)
		return (head);
	return (head->prev);
}
