/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:26:46 by dximenez          #+#    #+#             */
/*   Updated: 2024/03/14 14:16:40 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack **s)
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

static void	sort_five(t_stack **a, t_stack **b)
{
	while (ft_lst_size(a) > 3)
		ft_pb(a, b);
	sort_three(a);
	while (ft_lst_size(b) > 0)
	{
		ft_pa(a, b);
		if ((*a)->val > (*a)->next->val)
			ft_ra(a);
	}
}

void	small_sort(t_stack **a, t_stack **b)
{
	if (ft_lst_size(a) < 3)
	{
		if ((*a)->val > (*a)->next->val)
			ft_sa(a);
	}
	else if (ft_lst_size(a) == 3)
		sort_three(a);
	else
		sort_five(a, b);
}

void	big_sort(t_stack **a, t_stack **b)
{
	int	max_bits;
	int	size;
	int	i;
	int	j;
	int	val;

	max_bits = 0;
	size = ft_lst_size(a) - 1;
	i = 0;
	j = 0;
	while ((size >> max_bits) != 0)
		++max_bits;
	while (i < max_bits)
	{
		while (j < size)
		{
			val = (*a)->val;
			if (((val >> i) & 1) == 1)
				ft_ra(a);
			else
				ft_pb(a, b);
			++j;
		}
		while (ft_lst_size(b) > 0)
			ft_pa(a, b);
		++i;
		j = 0;
	}
}
