/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchehbi <lchehbi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 19:00:00 by lchehbi           #+#    #+#             */
/*   Updated: 2026/06/20 20:07:45 by lchehbi          ###   ########.fr       */
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

static void	check_parse_result(int argc, char *argv[],
						int expected_size, int expected_first)
{
	t_node	*stack;

	stack = parse_arguments(argc, argv);
	assert(stack_size(stack) == expected_size);
	assert(stack->value == expected_first);
	free_stack(stack);
}

void	test_parsing(void)
{
	char	*argv1[4];
	char	*argv2[2];
	char	*argv3[4];

	argv1[0] = "push_swap";
	argv1[1] = "3";
	argv1[2] = "2";
	argv1[3] = "1";
	argv2[0] = "push_swap";
	argv2[1] = "3 2 1";
	argv3[0] = "push_swap";
	argv3[1] = "5 4";
	argv3[2] = "3";
	argv3[3] = "2 1";
	check_parse_result(4, argv1, 3, 3);
	check_parse_result(2, argv2, 3, 3);
	check_parse_result(4, argv3, 5, 5);
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
