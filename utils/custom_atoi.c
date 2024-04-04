/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 21:34:54 by dximenez          #+#    #+#             */
/*   Updated: 2024/03/20 16:46:50 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	get_symbol(char c, size_t *i)
{
	if (c == '-' || c == '+')
	{
		if (c == '-')
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
	if (ft_strlen(s) == 1 && (s[0] < '0' || s[0] > '9'))
		res.status = 0;
	symbol = get_symbol(s[0], &i);
	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
			res.num = (res.num * 10) + (s[i] - '0');
		else
			res.status = 0;
		i++;
	}
	res.num = symbol * res.num;
	return (res);
}
