/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:50:16 by dximenez          #+#    #+#             */
/*   Updated: 2024/04/05 17:36:03 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack_node
{
	int					val;
	int					old;
	int					trash;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack;

typedef struct s_response
{
	long	num;
	int		status;
}	t_response;

// Operations
void		ft_pa(t_stack **a, t_stack **b);
void		ft_pb(t_stack **a, t_stack **b);

void		ft_sa(t_stack **a);
void		ft_sb(t_stack **b);
void		ft_ss(t_stack **a, t_stack **b);

void		ft_ra(t_stack **a);
void		ft_rb(t_stack **b);
void		ft_rr(t_stack **a, t_stack **b);

void		ft_rra(t_stack **a);
void		ft_rrb(t_stack **b);
void		ft_rrr(t_stack **a, t_stack **b);

// Array
void		sort_array(int **array, size_t size);
void		sort_swap_array(t_stack **lst, int *array, size_t size);
void		find_swap(t_stack **lst, int num, int swap);

// Sort
void		small_sort(t_stack **a, t_stack **b);
void		big_sort(t_stack **a, t_stack **b);

// List utils
t_stack		*ft_last_stack(t_stack *lst);
t_stack		*ft_new_stack(int value);
t_stack		*ft_add_back_stack(t_stack *lst, t_stack *new);
int			ft_lst_size(t_stack **lst);
void		ft_print_stacks(t_stack *stack_a, t_stack *stack_b);
int			ft_is_sorted(t_stack *a);
int			ft_number_index(t_stack **a, int number);

// Atoi
size_t		count_words(char const *s, char del);
t_response	ft_atoi_ps(char *s);

// Int utils
int			array_contains(int num, int **array, int len);

// Errors
void		show_error(void);

// Frees
void		free_array_words(char	**mem, size_t size);
void		free_stack(t_stack **a);
void		free_check(char **mem, size_t size, int check);

#endif
