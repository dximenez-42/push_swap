/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:26:46 by dximenez          #+#    #+#             */
/*   Updated: 2024/02/23 20:13:31 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack **a)
{
	if (ft_max_stack(*a) == (*a)->value)
	{
		ft_ra(a);
		// ft_sa(a);	// if still unsorted
	}
	else if (ft_min_stack(*a) == (*a)->value)
	{
		ft_rra(a);
		ft_sa(a);
	}
	else
	{
		
	}
}