/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:19:25 by dximenez          #+#    #+#             */
/*   Updated: 2024/02/23 19:11:31 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 # Reverse rotate
 * Shift down the elements by one.
 * The last element becomes the first.
*/
static void	reverse_rotate(t_stack **lst)
{
	t_stack	*last;

	if (*lst == NULL)
		return ;
	last = ft_last_stack(*lst);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *lst;
	(*lst)->prev = last;
	(*lst) = last;
}

/**
 # Reverse rotate A
 * Shift down the elements of A by one.
 * The last element becomes the first.
*/
void	ft_rra(t_stack **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

/**
 # Reverse rotate B
 * Shift down the elements of B by one.
 * The last element becomes the first.
*/
void	ft_rrb(t_stack **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

/**
 # Reverse rotate A & B
 * Shift down the elements of A and B by one.
 * The last element becomes the first on each stack.
*/
void	ft_rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
