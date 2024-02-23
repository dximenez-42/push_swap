/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:19:22 by dximenez          #+#    #+#             */
/*   Updated: 2024/02/23 17:37:21 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 # Swap
 * Swap the 2 first elements at the top of the stack
*/
static void	swap(t_stack **lst)
{
	t_stack	*swap;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	swap = *lst;
	(*lst) = (*lst)->next;
	swap->next = (*lst)->next;
	(*lst)->next = swap;
}

/**
 # Swap A
 * Swap the 2 first elements at the top of the stack A
*/
void	ft_sa(t_stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

/**
 # Swap B
 * Swap the 2 first elements at the top of the stack B
*/
void	ft_sb(t_stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

/**
 # Swap A & B
 * Swap the 2 first elements at the top of the stack A and B
*/
void	ft_ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
