/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:26:46 by dximenez          #+#    #+#             */
/*   Updated: 2024/03/01 17:39:59 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	// if ((*a)->val > (*a)->next->val)
	// 	ft_ra(a);
	// ft_pa(a, b);
	// if ((*a)->val > (*a)->next->val)
	// 	ft_ra(a);
}