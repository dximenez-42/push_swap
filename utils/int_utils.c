/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:45:11 by dximenez          #+#    #+#             */
/*   Updated: 2024/03/17 21:41:01 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	array_contains(int num, int **array, int index)
{
	int	i;

	i = 0;
	while (i <= index)
	{
		// if ((*array)[i] == num && (i != 0 && num == 0))
		if ((*array)[i] == num || (num == 0 && i != index))
		{
			printf("already found: %d in index: %d\n", num, i);
			return (1);
		}
		++i;
	}
	printf("not found: %d\n", num);
	(*array)[index] = num;
	return (0);
}
