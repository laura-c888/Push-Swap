/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchehbi <lchehbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 19:00:00 by lchehbi           #+#    #+#             */
/*   Updated: 2026/06/20 19:00:00 by lchehbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to_closest_in_chunk(t_node **a, int limit)
{
	t_node	*curr;
	int		top_pos;
	int		bot_pos;
	int		i;

	top_pos = -1;
	bot_pos = -1;
	curr = *a;
	i = 0;
	while (curr)
	{
		if (curr->index < limit)
		{
			if (top_pos == -1)
				top_pos = i;
			bot_pos = i;
		}
		curr = curr->next;
		i++;
	}
	exec_rotations(a, top_pos, bot_pos);
}

void	push_chunks_to_b(t_stacks *stacks, int chunk_size)
{
	int	min_idx;
	int	limit;

	min_idx = 0;
	while (stacks->a)
	{
		limit = min_idx + chunk_size;
		if (stacks->a->index < limit)
		{
			pb(&stacks->a, &stacks->b);
			if (stacks->b->index < min_idx + chunk_size / 2)
				rb(&stacks->b);
			min_idx++;
		}
		else
			rotate_to_closest_in_chunk(&stacks->a, limit);
	}
}

void	restore_b_to_a(t_stacks *stacks)
{
	int	max_pos;
	int	b_size;
	int	dist;

	while (stacks->b)
	{
		max_pos = find_max_position(stacks->b);
		b_size = stack_size(stacks->b);
		if (max_pos <= b_size / 2)
		{
			while (max_pos-- > 0)
				rb(&stacks->b);
		}
		else
		{
			dist = b_size - max_pos;
			while (dist-- > 0)
				rrb(&stacks->b);
		}
		pa(&stacks->a, &stacks->b);
	}
}

void	sort_medium(t_stacks *stacks)
{
	int	size;
	int	chunk_size;

	size = stack_size(stacks->a);
	if (size <= 5)
	{
		sort_small(stacks);
		return ;
	}
	if (size <= 100)
		chunk_size = 15;
	else
		chunk_size = 31;
	push_chunks_to_b(stacks, chunk_size);
	restore_b_to_a(stacks);
}
