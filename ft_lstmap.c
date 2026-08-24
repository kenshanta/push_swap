/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziental <jziental@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:46:06 by jziental          #+#    #+#             */
/*   Updated: 2026/08/21 19:51:00 by jziental         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_map;
	t_list	*node_map;
	void	*content;

	lst_map = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		content = f(lst->content);
		if (!content)
		{
			ft_lstclear(&lst_map, del);
			return (NULL);
		}
		node_map = ft_lstnew(content);
		ft_lstadd_back(&lst_map, node_map);
		lst = lst->next;
	}
	return (lst_map);
}
