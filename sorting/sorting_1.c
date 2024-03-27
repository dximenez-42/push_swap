/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:19:33 by dximenez          #+#    #+#             */
/*   Updated: 2024/03/27 21:15:16 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	clear_trash(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *a;
	t_stack *b;

	a = stack_a;
	b = stack_b;
	while (a != NULL)
	{
		a->trash = 0;
		a = a->next;
	}
	while (b != NULL)
	{
		b->trash = 0;
		b = b->next;
	}
}

void	step_one(t_stack **a, t_stack **b, int max)
{
	ft_pb(a, b);
	while ((*b)->val != 0 || ft_last_stack(*b)->val != max)
	{
		if ((*b)->val == 0 && ft_last_stack(*b)->val == max)
			break ;
		if ((*a)->val < (*b)->val)
			ft_pb(a, b);
		else if ((*a)->val > ft_last_stack(*b)->val)
		{
			ft_pb(a, b);
			ft_rb(b);
		}
		else
			ft_ra(a);
	}
}

void	join_stacks(t_stack **a, t_stack **b, char dest)
{
	if (dest == 'b')
		while (ft_lst_size(a) != 0)
			ft_pb(a, b);
	else
		while (ft_lst_size(b) != 0)
			ft_pa(a, b);
}

void	step_three(t_stack **a, t_stack **b)
{
	if ((*b)->val != 0)
		ft_pa(a, b);
	while ((*b)->val != 0)
	{
		if((*b)->val < (*a)->val)
			ft_pa(a, b);
		else if ((*b)->val > ft_last_stack(*a)->val)
		{
			ft_pa(a, b);
			ft_ra(a);
		}
		else
			ft_rb(b);
	}
}

void	step_four(t_stack **a, t_stack **b, int max)
{
	while (ft_last_stack(*b)->val != max)
	{
		ft_rrb(b);
		(*b)->trash = 1;
	}
	join_stacks(a, b, 'a');
}

void	merge(t_stack **a, t_stack **b)
{
	t_stack *last;

	while ((*b) == NULL || (*b)->val != 0)
	{
		last = ft_last_stack(*a);
		if ((*a)->val > last->val && !(*a)->trash)
			ft_pb(a, b);
		else if ((*a)->val < last->val && !last->trash)
		{
			ft_rra(a);
			ft_pb(a, b);
		}
		else
			ft_pb(a, b);
	}
}
