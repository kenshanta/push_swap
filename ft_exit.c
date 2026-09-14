/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziental <jziental@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 13:33:26 by jziental          #+#    #+#             */
/*   Updated: 2026/09/13 17:09:19 by jziental         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(t_stacks **lst, int say_error)
{
	if (lst)
		ft_toolsfree(lst);
	if (say_error)
		write(2, "Error\n", 6);
	exit(1);
}
