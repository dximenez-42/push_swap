/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:46:02 by dximenez          #+#    #+#             */
/*   Updated: 2024/02/23 19:12:21 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ft_initialize_stack(int argc, char *argv[])
{
	t_stack	*lst;
	int		i;

	lst = ft_new_stack(0, ft_atoi(argv[1]));
	i = 1;
	while ((i + 1) < argc)
	{
		ft_add_back_stack(lst, ft_new_stack(i, ft_atoi(argv[i + 1])));
		++i;
	}
	return (lst);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = ft_initialize_stack(argc, argv);
	b = NULL;
	ft_print_stack(a, 'A');
	ft_print_stack(b, 'B');
}