/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:05:25 by dximenez          #+#    #+#             */
/*   Updated: 2024/03/16 18:50:19 by dximenez         ###   ########.fr       */
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
