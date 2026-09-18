/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziental <jziental@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 14:20:46 by jziental          #+#    #+#             */
/*   Updated: 2026/09/18 16:49:16 by jziental         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	which_startegy(t_stacks *toolbox)
{
	if (toolbox->chosen_strategy == STRATEGY_SIMPLE)
		ft_putstr_fd("O(n²)", 2);
	if (toolbox->chosen_strategy == STRATEGY_MEDIUM)
		ft_putstr_fd("O(n√n)", 2);
	if (toolbox->chosen_strategy == STRATEGY_COMPLEX)
		ft_putstr_fd("O(nlog(n))", 2);
}

static void	print_strategy(t_stacks *toolbox)
{
	if (toolbox->strategy_flag == STRATEGY_ADAPTIVE)
	{
		ft_putstr_fd("Adaptive / ", 2);
		which_startegy(toolbox);
	}
	else if (toolbox->strategy_flag == STRATEGY_SIMPLE)
		ft_putstr_fd("Simple / O(n²)", 2);
	else if (toolbox->strategy_flag == STRATEGY_MEDIUM)
		ft_putstr_fd("Medium / O(n√n)", 2);
	else if (toolbox->strategy_flag == STRATEGY_COMPLEX)
		ft_putstr_fd("Complex / O(nlog(n))", 2);
}

static void	print_disorder_bench(t_stacks *toolbox)
{
	int	disorder;
	int	whole;
	int	frac;

	if (!toolbox || toolbox->pairs == 0)
	{
		ft_putstr_fd("[bench] disorder:  0.00%\n", 2);
		return ;
	}
	disorder = (int)(((long long)toolbox->mistakes * 10000) / toolbox->pairs);
	whole = disorder / 100;
	frac = disorder % 100;
	ft_putstr_fd("[bench] disorder:  ", 2);
	ft_putnbr_fd(whole, 2);
	ft_putstr_fd(".", 2);
	if (frac < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(frac, 2);
	ft_putstr_fd("%\n", 2);
}

static void	print_operations_counts(t_stacks *toolbox)
{
	ft_putstr_fd("\n[bench] total_ops: ", 2);
	ft_putnbr_fd(toolbox->total_ops, 2);
	ft_putstr_fd("\n[bench] sa: ", 2);
	ft_putnbr_fd(toolbox->c_sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(toolbox->c_sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(toolbox->c_ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(toolbox->c_pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(toolbox->c_pb, 2);
	ft_putstr_fd("\n[bench] ra: ", 2);
	ft_putnbr_fd(toolbox->c_ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(toolbox->c_rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(toolbox->c_rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(toolbox->c_rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(toolbox->c_rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(toolbox->c_rrr, 2);
}

void	benchmark(t_stacks **toolbox)
{
	print_disorder_bench(*toolbox);
	ft_putstr_fd("[bench] strategy: ", 2);
	print_strategy(*toolbox);
	print_operations_counts(*toolbox);
}
