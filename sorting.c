/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:26:46 by dximenez          #+#    #+#             */
/*   Updated: 2024/03/13 14:18:18 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_array(int **array, size_t size)
{
	size_t	i;
	size_t	j;
	int		swap;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		while (j < size - 1)
		{
			if ((*array)[j] > (*array)[j + 1])
			{
				swap = (*array)[j];
				(*array)[j] = (*array)[j + 1];
				(*array)[j + 1] = swap;
			}
			++j;
		}
		j = 0;
		++i;
	}
}

void	sort_swap_array(t_stack **lst, int *array, size_t size)
{
	t_stack	*current;
	int		i;

	i = 0;
	sort_array(&array, size);
	while (i < size)
	{
		find_swap(lst, array[i], i);
		++i;
	}
}

void	find_swap(t_stack **lst, int num, int swap)
{
	t_stack	*stack;

	stack = *lst;
	while (stack != NULL)
	{
		if (stack->val == num)
		{
			stack->val = swap;
			return ;
		}
		stack = stack->next;
	}
}

void	sort_two(t_stack **s)
{
	if ((*s)->val > (*s)->next->val)
		ft_sa(s);
}

/**
 * 
 * First	213
 * Second	231
 * Third	312
*/
void	sort_three(t_stack **s)
{
	if ((*s)->val > (*s)->next->val && (*s)->val < (*s)->next->next->val)
		ft_sa(s);
	if ((*s)->val < (*s)->next->val && (*s)->val > (*s)->next->next->val)
		ft_rra(s);
	if ((*s)->val > (*s)->next->val && (*s)->val > (*s)->next->next->val)
		ft_ra(s);
	if (!ft_is_sorted(*s, 3))
		return (sort_three(s));
}

void	sort_five(t_stack **a, t_stack **b)
{
	ft_pb(a, b);
	ft_pb(a, b);
	sort_three(a);
	// ft_pa(a, b);
	// ft_pa(a, b);
	// ft_pa(a, b);
	// if ((*a)->val > (*a)->next->val)
	// 	ft_ra(a);
	// ft_pa(a, b);
	// if ((*a)->val > (*a)->next->val)
	// 	ft_ra(a);
}