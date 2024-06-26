/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:24:09 by dximenez          #+#    #+#             */
/*   Updated: 2024/03/27 20:25:12 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_last_stack(t_stack *lst)
{
	t_stack	*current;

	current = lst;
	while (current != NULL)
	{
		if (current->next == NULL)
			return (current);
		current = current->next;
	}
	return (0);
}

t_stack	*ft_new_stack(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return (show_error(), NULL);
	new->val = value;
	new->trash = 0;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_stack	*ft_add_back_stack(t_stack *lst, t_stack *new)
{
	t_stack	*last;

	if (lst == NULL)
		lst = new;
	else
	{
		last = ft_last_stack(lst);
		last->next = new;
		new->prev = last;
		new->next = NULL;
	}
	return (lst);
}

int	ft_lst_size(t_stack **lst)
{
	t_stack	*current;
	size_t	i;

	i = 0;
	current = *lst;
	while (current != 0)
	{
		current = current->next;
		++i;
	}
	return (i);
}
