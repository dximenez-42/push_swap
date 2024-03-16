/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 21:34:54 by dximenez          #+#    #+#             */
/*   Updated: 2024/03/14 18:33:02 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

static int	get_symbol(char *s, size_t *i)
{
	if (s[*i] == '-' || s[*i] == '+')
	{
		if (s[*i] == '-')
		{
			++(*i);
			return (-1);
		}
	}
	return (1);
}

t_response	ft_atoi_ps(char *s)
{
	size_t		i;
	t_response	res;
	int			symbol;

	i = 0;
	res.num = 0;
	res.status = 1;
	symbol = 1;
	while (is_space(s[i]))
		i++;
	symbol = get_symbol(s, &i);
	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			res.num = (res.num * 10) + (s[i] - '0');
			i++;
		}
		else
			res.status = 0;
	}
	if ((symbol * res.num) > 2147483647 || (symbol * res.num) < -2147483648)
		res.status = 0;
	// printf("atoi val: %d, status: %d\n", res.num, res.status);
	return (res);
}
