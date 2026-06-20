/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchehbi <lchehbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 19:00:00 by lchehbi           #+#    #+#             */
/*   Updated: 2026/06/20 19:00:00 by lchehbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "../push_swap.h"

t_node	*build_stack(int values[], int count)
{
	t_node	*stack;
	int		i;

	stack = NULL;
	i = 0;
	while (i < count)
	{
		push_bottom(&stack, new_node(values[i]));
		i++;
	}
	assign_indices(stack);
	return (stack);
}

void	assert_stack_values(t_node *stack, int expected[], int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		assert(stack != NULL);
		assert(stack->value == expected[i]);
		stack = stack->next;
		i++;
	}
	assert(stack == NULL);
}

void	test_parsing(void)
{
	char	*argv[4];
	char	*argv2[2];
	char	*argv3[4];
	t_node	*stack;

	argv[0] = "push_swap";
	argv[1] = "3";
	argv[2] = "2";
	argv[3] = "1";
	argv2[0] = "push_swap";
	argv2[1] = "3 2 1";
	argv3[0] = "push_swap";
	argv3[1] = "5 4";
	argv3[2] = "3";
	argv3[3] = "2 1";
	stack = parse_arguments(4, argv);
	assert(stack_size(stack) == 3);
	assert(stack->value == 3);
	assert(stack->next->value == 2);
	free_stack(stack);
	stack = parse_arguments(2, argv2);
	assert(stack_size(stack) == 3);
	assert(stack->value == 3);
	free_stack(stack);
	stack = parse_arguments(4, argv3);
	assert(stack_size(stack) == 5);
	assert(stack->value == 5);
	free_stack(stack);
}

void	test_swap_and_rotate(void)
{
	int		input[3];
	int		expected_swap[3];
	int		expected_rotate[3];
	t_node	*stack;

	input[0] = 1;
	input[1] = 2;
	input[2] = 3;
	expected_swap[0] = 2;
	expected_swap[1] = 1;
	expected_swap[2] = 3;
	expected_rotate[0] = 1;
	expected_rotate[1] = 3;
	expected_rotate[2] = 2;
	stack = build_stack(input, 3);
	sa(&stack);
	assert_stack_values(stack, expected_swap, 3);
	ra(&stack);
	assert_stack_values(stack, expected_rotate, 3);
	rra(&stack);
	assert_stack_values(stack, expected_swap, 3);
	free_stack(stack);
}
