/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:26:46 by dximenez          #+#    #+#             */
/*   Updated: 2024/03/22 16:46:09 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack **s)
{
	if ((*s)->val > (*s)->next->val && (*s)->val > (*s)->next->next->val)
		ft_ra(s);
	else if ((*s)->val > (*s)->next->val)
		ft_sa(s);
	else if ((*s)->val < (*s)->next->val)
		ft_rra(s);
	if (!ft_is_sorted(*s))
		sort_three(s);
}

static void	sort_five(t_stack **a, t_stack **b)
{
	int	pos;
	int	i;

	i = 0;
	while (ft_lst_size(a) > 3)
	{
		pos = ft_number_index(a, i);
		if (pos == 0)
		{
			ft_pb(a, b);
			++i;
		}
		else if (pos <= ft_lst_size(a) / 2)
			ft_ra(a);
		else
			ft_rra(a);
	}
	sort_three(a);
	while (ft_lst_size(b) > 0)
		ft_pa(a, b);
}

void	small_sort(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_lst_size(a);
	if (size == 2)
	{
		if ((*a)->val > (*a)->next->val)
			ft_sa(a);
	}
	else if (size == 3)
		sort_three(a);
	else
		sort_five(a, b);
}

void	big_sort(t_stack **a, t_stack **b)
{
	int	pos;
	int	i;

	i = 0;
	while (ft_lst_size(a) > 3)
	{
		pos = ft_number_index(a, i);
		if (pos == -1)
		{
			printf("#################ERROR##############      %d\n", i);
			i++;
			continue ;
		}
		// if (i >= 87)
		// 	ft_print_stacks(*a, *b);
		if ((*a)->val == i || ((*a)->val == i + 1 && ft_lst_size(a) > 4))
		{
			ft_pb(a, b);
			if ((*b)->next != NULL && (*b)->val < (*b)->next->val)
				ft_sb(b);
			if ((*a)->val == i)
				i++;
		}
		else if (pos <= ft_lst_size(a) / 2)
			ft_ra(a);
		else
			ft_rra(a);
	}
	sort_three(a);
	while (ft_lst_size(b) > 0)
		ft_pa(a, b);
}
