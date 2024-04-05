/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:26:10 by dximenez          #+#    #+#             */
/*   Updated: 2024/04/05 14:31:50 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	free_stack(t_stack **a)
{
	t_stack	*next;

	while ((*a) != NULL)
	{
		next = (*a)->next;
		free((*a));
		(*a) = next;
	}
}

void	free_check(char **mem, size_t size, int check)
{
	if (check == 1)
	{
		free_array_words(mem, size);
	}
}
