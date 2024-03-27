/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:45:11 by dximenez          #+#    #+#             */
/*   Updated: 2024/03/20 16:48:35 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	array_contains(int num, int **array, int index)
{
	int	i;

	i = 0;
	while (i <= index)
	{
		if ((*array)[i] == num && (num == 0 && i < index))
			return (1);
		++i;
	}
	(*array)[index] = num;
	return (0);
}
