/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziental <jziental@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 17:37:27 by jziental          #+#    #+#             */
/*   Updated: 2026/08/23 19:19:39 by jziental         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_list
{
	int				num;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;
int		ft_putchar(char c);
int		ft_printf(const char *format, ...);
int		ft_parse(va_list args, char format);
int		ft_putstr(char *c);
int		ft_putint(int c);
int		ft_putuint(unsigned int i);
int		ft_puthex(unsigned long long i, char x);
int		ft_putptr(void *ptr);
char	**ft_split(char const *s, char c);
#endif
