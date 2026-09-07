/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziental <jziental@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 19:42:32 by jziental          #+#    #+#             */
/*   Updated: 2026/09/02 17:40:43 by jziental         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
