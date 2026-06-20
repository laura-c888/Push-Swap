/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchehbi <lchehbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 19:00:00 by lchehbi           #+#    #+#             */
/*   Updated: 2026/06/20 19:00:00 by lchehbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_position(t_node *stack)
{
	int	position;
	int	min_index;
	int	i;

	position = 0;
	i = 0;
	min_index = stack->index;
	while (stack)
	{
		if (stack->index < min_index)
		{
			min_index = stack->index;
			position = i;
		}
		stack = stack->next;
		i++;
	}
	return (position);
}

void	rotate_to_top(t_node **stack, int position)
{
	int	size;

	size = stack_size(*stack);
	if (position <= size / 2)
	{
		while (position-- > 0)
			ra(stack);
	}
	else
	{
		position = size - position;
		while (position-- > 0)
			rra(stack);
	}
}

static void	sort_three_nodes(t_stacks *stacks)
{
	int	first;
	int	second;
	int	third;

	first = stacks->a->index;
	second = stacks->a->next->index;
	third = stacks->a->next->next->index;
	if (first < second && second < third)
		return ;
	if (first > second && second < third && first < third)
		sa(&stacks->a);
	else if (first > second && second > third)
	{
		sa(&stacks->a);
		rra(&stacks->a);
	}
	else if (first > second && second < third && first > third)
		ra(&stacks->a);
	else if (first < second && second > third && first < third)
	{
		sa(&stacks->a);
		ra(&stacks->a);
	}
	else if (first < second && second > third && first > third)
		rra(&stacks->a);
}

static void	sort_five_nodes(t_stacks *stacks)
{
	int	position;

	while (stack_size(stacks->a) > 3)
	{
		position = find_min_position(stacks->a);
		rotate_to_top(&stacks->a, position);
		pb(&stacks->a, &stacks->b);
	}
	sort_three_nodes(stacks);
	while (stacks->b)
		pa(&stacks->a, &stacks->b);
}

void	sort_small(t_stacks *stacks)
{
	int	size;

	size = stack_size(stacks->a);
	if (size <= 1 || stack_sorted(stacks->a))
		return ;
	if (size == 2)
	{
		if (stacks->a->value > stacks->a->next->value)
			sa(&stacks->a);
		return ;
	}
	if (size == 3)
		sort_three_nodes(stacks);
	else
		sort_five_nodes(stacks);
}
