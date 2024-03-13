/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:46:02 by dximenez          #+#    #+#             */
/*   Updated: 2024/03/13 14:19:39 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ft_initialize_stack(int argc, char *argv[], int **array)
{
	t_stack	*lst;
	char	**numbers;
	int		i;

	if (argc == 2)
	{
		numbers = ft_split(argv[1], ' ');
		argc = count_words(argv[1], ' ') + 1;
	}
	else
		numbers = argv + 1;
	(*array) = ft_calloc(argc - 1, sizeof(int));
	if ((*array) == NULL)
		show_error();
	lst = NULL;
	i = 0;
	while ((i + 1) < argc)
	{
		check_array_contains(ft_atoi_ps(numbers[i]), array, i);
		lst = ft_add_back_stack(lst, ft_new_stack(i, ft_atoi_ps(numbers[i])));
		++i;
	}
	return (lst);
}


int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		*array;

	a = ft_initialize_stack(argc, argv, &array);
	b = NULL;
	if (ft_is_sorted(a, argc - 1) && a != NULL)
		return (printf("already sorted\n"), 0);
	sort_swap_array(&a, array, argc - 1);
	// sort_array(&array, argc - 1);

	// printf("is sorted?: %d\n", ft_is_sorted(a, argc - 1));

	// ft_print_stack(a, 'A');
	// ft_print_stack(b, 'B');
}
