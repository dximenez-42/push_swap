/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:50:16 by dximenez          #+#    #+#             */
/*   Updated: 2024/02/26 14:16:08 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack_node
{
	int					index;
	int					value;
	int					cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack;

// Operations
void	ft_pa(t_stack **a, t_stack **b);
void	ft_pb(t_stack **a, t_stack **b);

void	ft_sa(t_stack **a);
void	ft_sb(t_stack **b);
void	ft_ss(t_stack **a, t_stack **b);

void	ft_ra(t_stack **a);
void	ft_rb(t_stack **b);
void	ft_rr(t_stack **a, t_stack **b);

void	ft_rra(t_stack **a);
void	ft_rrb(t_stack **b);
void	ft_rrr(t_stack **a, t_stack **b);

// List utils
t_stack	*ft_last_stack(t_stack *lst);
t_stack	*ft_new_stack(int index, int value);
t_stack	*ft_add_back_stack(t_stack *lst, t_stack *new);
void	ft_print_stack(t_stack *lst, char letter);

// Str utils
size_t	count_words(char const *s, char del);
int		ft_atoi_ps(char *s);

int		check_array_contains(int num, int *array, int len);

int		ft_min_stack(t_stack *lst);
int		ft_max_stack(t_stack *lst);

#endif