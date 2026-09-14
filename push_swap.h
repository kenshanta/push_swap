/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziental <jziental@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 17:37:27 by jziental          #+#    #+#             */
/*   Updated: 2026/09/14 19:28:49 by jziental         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
//circular doubly linked list
typedef struct s_list
{
	int				num;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;
//toolbox struct
typedef struct s_stacks
{
	t_list	*a;
	t_list	*b;
	int		c_pa;
	int		c_pb;
	int		c_sa;
	int		c_sb;
	int		c_ss;
	int		c_ra;
	int		c_rb;
	int		c_rr;
	int		c_rra;
	int		c_rrb;
	int		c_rrr;
	int		pairs;
	int		mistakes;
	int		total_ops;
	int		is_benchmark;
	int		strategy_flag;
	int		chosen_strategy;
}	t_stacks;
//strategies
void	push_swap(t_stacks **toolbox);
void	simple_sort (t_stacks *toolbox);
void	complex_sort (t_stacks *toolbox);
void    medium_sort(t_stacks *toolbox);
void	assign_indexes(t_stacks **toolbox);
//stack maintenance
t_stacks	*stacks_init(void);
t_list		*ft_lstnew(int content);
t_list		*ft_lstlast(t_list *head);
void		ft_lstclear(t_list **lst);
void		ft_lstdelone(t_list **lst);
int			stack_length(t_list *stack);
void		ft_toolsfree(t_stacks **stacks);
void		ft_exit(t_stacks **lst, int say_error);
void		ft_lstadd_front(t_list **stack, t_list *new);
void		ft_lstadd_back(t_list **stack, t_list *new);
//stack operations helpers
int			swap(t_list **stack);
int			rotate(t_list **stack);
int			rev_rotate(t_list **stack);
int			push(t_list **source, t_list **dest);
//stack operations
void		pa(t_stacks *toolbox);
void		pb(t_stacks *toolbox);
void		sa(t_stacks *toolbox);
void		sb(t_stacks *toolbox);
void		ss(t_stacks *toolbox);
void		ra(t_stacks *toolbox);
void		rb(t_stacks *toolbox);
void		rr(t_stacks *toolbox);
void		rra(t_stacks *toolbox);
void		rrb(t_stacks *toolbox);
void		rrr(t_stacks *toolbox);
//printing output
int			ft_putint(int c);
int			ft_putstr(char *c);
int			ft_putchar(char c);
int			ft_putptr(void *ptr);
int			ft_putuint(unsigned int i);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
void		benchmark(t_stacks **toolbox);
int			ft_printf(const char *format, ...);
int			ft_parse(va_list args, char format);
int			ft_puthex(unsigned long long i, char x);
//parsing
# define STRATEGY_ADAPTIVE 0
# define STRATEGY_SIMPLE 1
# define STRATEGY_MEDIUM 2
# define STRATEGY_COMPLEX 3
int			ft_isdigit(int c);
int			ft_onlydigits(char **str);
long long	ft_atoi(const char *nptr);
int			has_whitespaces(char *nptr);
char		**ft_split(char const *s, char c);
void		*ft_calloc(size_t nmemb, size_t size);
void		take_ints(char **str, t_stacks *stacks);
int			check_flags(char **av, t_stacks *stacks);
int			ft_strcmp(const char *s1, const char *s2);
void 		compute_disorder(t_stacks **toolbox,  t_list *a);
void		check_write_args(int ac, char **av, t_stacks *stacks);
#endif
