/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:46:02 by dximenez          #+#    #+#             */
/*   Updated: 2024/03/18 18:50:04 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_response	check_input(char *str, int **array, int index)
{
	t_response	res;

	res = ft_atoi_ps(str);
	// printf("check_input val: %d, status: %d\n", res.num, res.status);
	if (array_contains(res.num, array, index) == 0 && res.status == 1)
	{
		// if (res.num < -214748368 || res.num > 214748367)
		// 	return (res);
		res.status = 1;
		// printf("check_input if\n");
		return (res);
	}
	else
	{
		// printf("check_input else\n");
		res.status = 0;
		return (res);
	}
}

static t_stack	*ft_initialize_stack(int *argc, char *argv[], int **array)
{
	t_stack		*lst;
	char		**numbers;
	int			i;
	t_response	value;

	if (*argc == 2)
	{
		numbers = ft_split(argv[1], ' ');
		*argc = count_words(argv[1], ' ') + 1;
	}
	else
		numbers = argv + 1;
	(*array) = malloc(*argc - 1 * sizeof(int));
	if ((*array) == NULL)
		return (NULL);
	lst = NULL;
	i = -1;
	while ((++i + 1) < *argc)
	{
		value = check_input(numbers[i], array, i);
		if (value.status == 0)
		{
			// printf("value.status == 0\n");
			return (NULL);
		}
		lst = ft_add_back_stack(lst, ft_new_stack(value.num));
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
	if (a == NULL)
		return (0);
	if (ft_is_sorted(a) && a != NULL)
		return (0);
	sort_swap_array(&a, array, argc - 1);
	// printf("%d\n", argc - 1);
	// if (argc - 1 <= 5)
	// 	printf("<= 5: %d\n", argc - 1);
	// 	// small_sort(&a, &b);
	// else
	// 	printf("> 5: %d\n", argc - 1);
	(void)b;
		// big_sort(&a, &b);
	// printf("\n\nis sorted?: %d\n", ft_is_sorted(a));
	// ft_print_stack(a, 'A');
	// ft_print_stack(b, 'B');
}
