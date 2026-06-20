/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addufour <addufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 19:00:00 by addufour          #+#    #+#             */
/*   Updated: 2026/06/20 19:00:00 by addufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	find_min_pos(t_stack *a)
{
	int	min;
	int	pos;
	int	min_pos;

	min = a->value;
	pos = 0;
	min_pos = 0;
	while (a)
	{
		if (a->value < min)
		{
			min = a->value;
			min_pos = pos;
		}
		pos++;
		a = a->next;
	}
	return (min_pos);
}

int	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

void	move_min_to_top(t_stack **a)
{
	int	min_pos;
	int	size;
	int	moves;

	min_pos = find_min_pos(*a);
	size = stack_size(*a);
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			ra(a);
	}
	else
	{
		moves = size - min_pos;
		while (moves-- > 0)
			rra(a);
	}
}
