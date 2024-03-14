/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:18:16 by dximenez          #+#    #+#             */
/*   Updated: 2024/03/14 13:25:33 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 # Push dst
 * Take the first element at the top of src and put it at the top of dst
 * Do nothing if src is empty
*/
static void	push(t_stack **dst, t_stack **src)
{
	t_stack	*swap;

	if (*src == NULL)
		return ;
	swap = (*src);
	(*src) = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	if (*dst != NULL)
		(*dst)->prev = swap;
	swap->next = (*dst);
	(*dst) = swap;
}

/**
 # Push A
 * Take the first element at the top of B and put it at the top of A
 * Do nothing if B is empty
*/
void	ft_pa(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

/**
 # Push b
 * Take the first element at the top of A and put it at the top of B
 * Do nothing if A is empty
*/
void	ft_pb(t_stack **a, t_stack **b)
{
	push(b, a);
	write(1, "pb\n", 3);
}
