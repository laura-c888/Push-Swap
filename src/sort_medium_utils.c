/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchehbi <lchehbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 19:00:00 by lchehbi           #+#    #+#             */
/*   Updated: 2026/06/20 19:00:00 by lchehbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_position(t_node *stack)
{
	int	position;
	int	max_index;
	int	i;

	position = 0;
	i = 0;
	max_index = stack->index;
	while (stack)
	{
		if (stack->index > max_index)
		{
			max_index = stack->index;
			position = i;
		}
		stack = stack->next;
		i++;
	}
	return (position);
}

void	exec_rotations(t_node **a, int top_pos, int bot_pos)
{
	int	i;

	if (top_pos <= stack_size(*a) - bot_pos)
	{
		while (top_pos-- > 0)
			ra(a);
	}
	else
	{
		i = stack_size(*a) - bot_pos;
		while (i-- > 0)
			rra(a);
	}
}
