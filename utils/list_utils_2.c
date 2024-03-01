/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:05:25 by dximenez          #+#    #+#             */
/*   Updated: 2024/02/27 13:58:46 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_is_sorted(t_stack *a, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (a->next != NULL && a->val > a->next->val)
			return (0);
		a = a->next;
		++i;
	}
	return (1);
}