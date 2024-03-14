/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:18:18 by dximenez          #+#    #+#             */
/*   Updated: 2024/02/23 17:37:56 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_stack **lst)
{
	t_stack	*first;
	t_stack	*last;

	if (*lst == NULL)
		return ;
	first = *lst;
	(*lst)->next->prev = NULL;
	(*lst) = (*lst)->next;
	first->next = NULL;
	last = ft_last_stack(*lst);
	first->prev = last;
	last->next = first;
}

/**
 # Rotate A
 * Shift up all the elements of A by one.
 * The first element becomes the last.
*/
void	ft_ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

/**
 # Rotate B
 * Shift up all the elements of B by one.
 * The first element becomes the last.
*/
void	ft_rb(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

/**
 # Rotate A & B
 * Shift up all the elements of A and B by one.
 * The first element becomes the last on each stack.
*/
void	ft_rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
