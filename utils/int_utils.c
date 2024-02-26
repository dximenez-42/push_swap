/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:45:11 by dximenez          #+#    #+#             */
/*   Updated: 2024/02/26 14:16:08 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_array_contains(int num, int *array, int index)
{
	int	i;

	i = 0;
	while (i <= index)
	{
		if (array[i] == num)
		{
			ft_printf("Error");
			exit(0);
		}
		++i;
	}
	array[index] = num;
	return (0);
}