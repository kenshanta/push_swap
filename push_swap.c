/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skovlekj <skovlekj@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 16:50:10 by jziental          #+#    #+#             */
/*   Updated: 2026/09/17 23:28:09 by skovlekj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	adapt_strategy(t_stacks **toolbox)
{
	float	disorder;

	if (!(*toolbox)->pairs)
		disorder = 0;
	else
		disorder = (float)(*toolbox)->mistakes / (*toolbox)->pairs;
	if (!(*toolbox)->mistakes)
		return (ft_exit(toolbox, 0));
	else if (disorder < 0.2)
		(*toolbox)->chosen_strategy = STRATEGY_SIMPLE;
	else if (disorder < 0.5)
		(*toolbox)->chosen_strategy = STRATEGY_MEDIUM;
	else
		(*toolbox)->chosen_strategy = STRATEGY_COMPLEX;
}

static int is_adaptive(t_stacks **toolbox)
{
	if ((*toolbox)->strategy_flag == STRATEGY_ADAPTIVE)
		return 1;
	return 0;
}

void	push_swap(t_stacks **toolbox)
{
	if (!is_adaptive(toolbox))
		(*toolbox)->chosen_strategy = (*toolbox)->strategy_flag;
	if ((*toolbox)->chosen_strategy == STRATEGY_SIMPLE)
		simple_sort(*toolbox);
	else if ((*toolbox)->chosen_strategy == STRATEGY_MEDIUM)
		medium_sort(*toolbox);
	else if ((*toolbox)->chosen_strategy == STRATEGY_COMPLEX)
		complex_sort(*toolbox);
	else
		simple_sort(*toolbox);
}

int	main(int ac, char **av)
{
	t_stacks	*toolbox;

	toolbox = stacks_init();
	check_write_args(ac, av, toolbox);
	assign_indexes(&toolbox);
	compute_disorder(&toolbox, toolbox->a);
	if (is_adaptive(&toolbox))
		adapt_strategy(&toolbox);
	push_swap(&toolbox);
	if (toolbox->is_benchmark)
		benchmark(&toolbox);
	return (ft_toolsfree(&toolbox), 0);
}
