/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:57:02 by dximenez          #+#    #+#             */
/*   Updated: 2024/03/14 17:41:01 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_array(int **array, size_t size)
{
	size_t	i;
	size_t	j;
	int		swap;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		while (j < size - 1)
		{
			if ((*array)[j] > (*array)[j + 1])
			{
				swap = (*array)[j];
				(*array)[j] = (*array)[j + 1];
				(*array)[j + 1] = swap;
			}
			++j;
		}
		j = 0;
		++i;
	}
}

void	sort_swap_array(t_stack **lst, int *array, size_t size)
{
	size_t	i;

	(void)lst;
	i = 0;
	sort_array(&array, size);
	while (i < size)
	{
		find_swap(lst, array[i], i);
		++i;
	}
}

void	find_swap(t_stack **lst, int num, int swap)
{
	t_stack	*stack;

	stack = *lst;
	while (stack != NULL)
	{
		if (stack->val == num)
		{
			stack->old = num;
			stack->val = swap;
			return ;
		}
		stack = stack->next;
	}
}

void	free_array_words(char	**mem, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free((void *)mem[i]);
		++i;
	}
	free(mem);
}
