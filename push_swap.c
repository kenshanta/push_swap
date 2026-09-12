/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziental <jziental@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 16:50:10 by jziental          #+#    #+#             */
/*   Updated: 2026/09/12 15:11:26 by jziental         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void	chose_strategy(t_stacks **toolbox)
{
	float	disorder;

	if ((*toolbox)->strategy_index != STRATEGY_ADAPTIVE)
		return ;
	if (!(*toolbox)->pairs)
		disorder = 0;
	else
		disorder = (float)(*toolbox)->mistakes / (*toolbox)->pairs;
	if (!(*toolbox)->mistakes)
		return ;
	else if (disorder < 0.2)
		(*toolbox)->strategy_index = STRATEGY_SIMPLE;
	else if (disorder < 0.5)
		(*toolbox)->strategy_index = STRATEGY_MEDIUM;
	else
		(*toolbox)->strategy_index = STRATEGY_COMPLEX;
}

void	push_swap(t_stacks **toolbox)
{
	chose_strategy(toolbox);
	if ((*toolbox)->strategy_index == STRATEGY_SIMPLE)
		simple_sort(*toolbox);
	else if ((*toolbox)->strategy_index == STRATEGY_MEDIUM)
		simple_sort(*toolbox);
	else if ((*toolbox)->strategy_index == STRATEGY_COMPLEX)
		simple_sort(*toolbox);
	else
		simple_sort(*toolbox);
}

int	main(int ac, char **av)
{
	t_stacks	*toolbox;

	toolbox = stacks_init();
	check_write_args(ac, av, toolbox);
	assign_indexes(&toolbox);
	push_swap(&toolbox);
	if (toolbox->is_benchmark)
		benchmark(&toolbox);
	return (ft_toolsfree(&toolbox), 0);
}

