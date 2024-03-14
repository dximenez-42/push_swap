/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:46:02 by dximenez          #+#    #+#             */
/*   Updated: 2024/03/14 14:50:53 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_input(char *str, int **array, int index)
{
	int num;

	num = ft_atoi_ps(str);
	if (!array_contains(num, array, index))
	{
		if (num < -214748368 || num > 214748367)
			return (show_error(), 0);
		return (num);
	}
	else
		return (show_error(), 0);
}

static t_stack	*ft_initialize_stack(int *argc, char *argv[], int **array)
{
	t_stack	*lst;
	char	**numbers;
	int		i;

	if (*argc == 2)
	{
		numbers = ft_split(argv[1], ' ');
		*argc = count_words(argv[1], ' ') + 1;
	}
	else
		numbers = argv + 1;
	(*array) = ft_calloc(*argc - 1, sizeof(int));
	if ((*array) == NULL)
		return (NULL);
	lst = NULL;
	i = 0;
	while ((i + 1) < *argc)
	{
		lst = ft_add_back_stack(
				lst, ft_new_stack(check_input(numbers[i], array, i)));
		++i;
	}
	return (lst);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		*array;

	a = ft_initialize_stack(&argc, argv, &array);
	b = NULL;
	if (ft_is_sorted(a, argc - 1) && a != NULL)
		return (0);
	sort_swap_array(&a, array, argc - 1);
	if (argc - 1 <= 5)
		small_sort(&a, &b);
	else
		big_sort(&a, &b);
	// printf("\n\nis sorted?: %d\n", ft_is_sorted(a, argc - 1));
	// ft_print_stack(a, 'A');
	// ft_print_stack(b, 'B');
}
