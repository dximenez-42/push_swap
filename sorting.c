/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:26:46 by dximenez          #+#    #+#             */
/*   Updated: 2024/02/27 13:58:36 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * 
 * Fir(*s)t	213
 * (*s)econd	231
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
