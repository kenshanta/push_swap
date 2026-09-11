/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziental <jziental@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 16:50:10 by jziental          #+#    #+#             */
/*   Updated: 2026/09/11 17:39:40 by jziental         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}
static void	take_ints(char **str, t_stacks *stacks)
{
	long long	num;
	t_list		*node;
	char		**tmp;
	int			i;
	int			j;

	i = 0;
	while (str[i])
	{
		tmp = ft_split(str[i], ' ');
		if (!tmp || !ft_onlydigits(tmp))		//if splited arguments aren't digits free and "Error\n"
			return (free_split(tmp), ft_exit(&stacks));
		j = 0;
		while (tmp[j])					//otherwise:
		{
			num = ft_atoi(tmp[j++]);	//convert char* to int and go on
			if (num > INT_MAX || num < INT_MIN)
				return (free_split(tmp), ft_exit(&stacks));
			node = ft_lstnew(num);
			if (!ft_onlydigits(tmp))
				return (free_split(tmp), ft_exit(&stacks));
			ft_lstadd_back(&stacks->a, node);
		}
		free_split(tmp);
	}
}

static int	check_flags(char **av, t_stacks *stacks)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!ft_strcmp(av[i], "--bench"))
			stacks->is_benchmark = 1;
		else if (!ft_strcmp(av[i], "--simple"))
			stacks->strategy_index = STRATEGY_SIMPLE;
		else if (!ft_strcmp(av[i], "--medium"))
			stacks->strategy_index = STRATEGY_MEDIUM;
		else if (!ft_strcmp(av[i], "--complex"))
			stacks->strategy_index = STRATEGY_COMPLEX;
		else if (!ft_strcmp(av[i], "--adaptive"))
			stacks->strategy_index = 0;
		else
			return(i);
		i++;
	}
	return (i);
}

static void	check_write_args(int ac, char **av, t_stacks *stacks)
{
	int	i;

	i = 1;
	if (ac < 2 || (ac == 2 && !av[1][0]))
		return (ft_exit(&stacks));
	else if (ac >= 2)
	{
		i = check_flags(av, stacks);
		if(av[i])
			take_ints(av + i, stacks);
		else
			ft_exit(&stacks);
	}
}

t_stacks	*stacks_init()
{
	t_stacks *stacks;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		ft_exit(&stacks);
	stacks->strategy_index = STRATEGY_ADAPTIVE;
	stacks->is_benchmark = 0;
	stacks->chosen_strategy = STRATEGY_ADAPTIVE;
	stacks->total_ops = 0;
	stacks->c_pa = 0;
	stacks->c_pb = 0;
	stacks->c_sa = 0;
	stacks->c_sb = 0;
	stacks->c_ss = 0;
	stacks->c_ra = 0;
	stacks->c_rb = 0;
	stacks->c_rr = 0;
	stacks->c_rra = 0;
	stacks->c_rrb = 0;
	stacks->c_rrr = 0;
	return (stacks);
}


int	main(int ac, char **av)
{
	t_stacks	*toolbox;
	t_list		*a;
	t_list		*b;
	int			i;

	toolbox = stacks_init();
	a = toolbox->a;
	b = toolbox->b;
	i = 1;
	check_write_args(ac, av, toolbox);
	if (toolbox->is_benchmark)
		benchmark(&toolbox);
	ft_printf("strat: %i\n", toolbox->strategy_index);
	ft_printf("bench: %i", toolbox->is_benchmark);
	return (0);
}

