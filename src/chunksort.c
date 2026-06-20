/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunksort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addufour <addufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 19:00:00 by addufour          #+#    #+#             */
/*   Updated: 2026/06/20 19:00:00 by addufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	get_chunk_size(int size)
{
	if (size <= 100)
		return (15);
	return (30);
}

static void	push_chunk(t_stack **a, t_stack **b, int *limit, int chk_size)
{
	pb(a, b);
	if (*b && (*b)->index < (*limit - chk_size / 2))
		rb(b);
	(*limit)++;
}

void	push_chunks_to_b2(t_stack **a, t_stack **b, int chunk_size)
{
	int	limit;

	limit = chunk_size;
	while (*a)
	{
		if ((*a)->index <= limit)
			push_chunk(a, b, &limit, chunk_size);
		else
			ra(a);
	}
}

static void	move_max_to_top(t_stack **b)
{
	int	pos;
	int	size;

	pos = find_max_position(*b);
	size = stack_size(*b);
	if (pos <= size / 2)
	{
		while (pos--)
			rb(b);
	}
	else
	{
		pos = size - pos;
		while (pos--)
			rrb(b);
	}
}

void	chunk_sort(t_stack **a, t_stack **b)
{
	int	chunk_size;

	chunk_size = get_chunk_size(stack_size(*a));
	push_chunks_to_b2(a, b, chunk_size);
	while (*b)
	{
		move_max_to_top(b);
		pa(a, b);
	}
}
