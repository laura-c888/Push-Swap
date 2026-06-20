/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchehbi <lchehbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 19:00:00 by lchehbi           #+#    #+#             */
/*   Updated: 2026/06/20 19:00:00 by lchehbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

void	skip_spaces(const char **str)
{
	while (is_space(**str))
		(*str)++;
}

long	parse_number(const char **str)
{
	long	result;
	int		sign;

	sign = 1;
	result = 0;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	if (**str < '0' || **str > '9')
		error_exit("Error");
	while (**str >= '0' && **str <= '9')
	{
		result = result * 10 + (**str - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && (result * -1) < INT_MIN))
			error_exit("Error");
		(*str)++;
	}
	return (result * sign);
}

bool	duplicate_value(t_node *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (true);
		stack = stack->next;
	}
	return (false);
}

int	compare_ints(const void *a, const void *b)
{
	return (*(const int *)a - *(const int *)b);
}
