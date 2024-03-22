/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:05:25 by dximenez          #+#    #+#             */
/*   Updated: 2024/03/22 15:52:33 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_is_sorted(t_stack *a)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lst_size(&a);
	while (i < size)
	{
		if (a->next != NULL && a->val > a->next->val)
			return (0);
		a = a->next;
		++i;
	}
	return (1);
}

int	ft_number_index(t_stack *a, int number)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lst_size(&a);
	while (i < size)
	{
		if (a->val == number)
			return (i);
		if (a->next != NULL)
			a = a->next;
		++i;
	}
	return (-1);
}

static void print_lists(t_stack *a, t_stack *b)
{
	if (a != NULL)
		ft_printf("%d\t", a->val);
	else
		ft_printf("\t");
	if (b != NULL)
		ft_printf("%d", b->val);
	else
		ft_printf("\t");
	ft_printf("\n");
}

void	ft_print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*a;
	t_stack	*b;

	a = stack_a;
	b = stack_b;
	ft_printf("\nA\tB\n");
	ft_printf("_\t_\n");
	while (a != NULL || b != NULL)
	{
		print_lists(a, b);
		if (a != NULL)
			a = a->next;
		if (b != NULL)
			b = b->next;
	}
	ft_printf("\n");
}
