/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:46:02 by dximenez          #+#    #+#             */
/*   Updated: 2024/04/06 19:27:59 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_response	check_input(char *str, int **array, int index)
{
	t_response	res;

	res = ft_atoi_ps(str);
	if (array_contains(res.num, array, index) == 0 && res.status == 1)
	{
		res.status = 1;
		return (res);
	}
	else
	{
		res.status = 0;
		return (res);
	}
}

static t_stack	*ft_initialize_stack(int argc, char **numbers, int **array)
{
	t_stack		*lst;
	int			i;
	t_response	value;

	(*array) = ft_calloc((argc - 1), sizeof(int));
	if ((*array) == NULL)
		return (NULL);
	lst = NULL;
	i = -1;
	while ((++i + 1) < argc)
	{
		value = check_input(numbers[i], array, i);
		if (value.status == 0)
			return (free_stack(&lst), NULL);
		lst = ft_add_back_stack(lst, ft_new_stack((int) value.num));
	}
	return (lst);
}

static char	**get_params(int *argc, char *argv[], int *check)
{
	char	**numbers;

	argv = argv + 1;
	if (*argc == 1)
		exit(1);
	else if (*argc == 2)
	{
		numbers = ft_split(argv[0], ' ');
		*argc = count_words(argv[0], ' ') + 1;
		*check = 1;
	}
	else
	{
		numbers = argv;
		*check = 0;
	}
	return (numbers);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		*array;
	int		check;
	char	**nums;

	nums = get_params(&argc, argv, &check);
	a = ft_initialize_stack(argc, nums, &array);
	b = NULL;
	if (a == NULL)
		return (show_error(), 0);
	if (ft_is_sorted(a) && a != NULL)
		return (exit(0), 0);
	sort_swap_array(&a, array, argc - 1);
	if (argc - 1 <= 5)
		small_sort(&a, &b);
	else
		big_sort(&a, &b);
	exit(0);
}
