/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchehbi <lchehbi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 19:00:00 by lchehbi           #+#    #+#             */
/*   Updated: 2026/06/20 20:06:40 by lchehbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "../push_swap.h"

t_node	*build_stack(int values[], int count);
void	assert_stack_values(t_node *stack, int expected[], int count);
void	test_parsing(void);
void	test_swap_and_rotate(void);

static void	test_push_and_pop(void)
{
	int		a_values[2];
	int		b_values[1];
	t_node	*a;
	t_node	*b;

	a_values[0] = 2;
	a_values[1] = 1;
	b_values[0] = 3;
	a = build_stack(a_values, 2);
	b = build_stack(b_values, 1);
	pb(&a, &b);
	assert(stack_size(a) == 1);
	assert(stack_size(b) == 2);
	pa(&a, &b);
	assert(stack_size(a) == 2);
	assert(stack_size(b) == 1);
	free_stack(a);
	free_stack(b);
}

static void	test_sort_small(void)
{
	int			values[3];
	int			expected[3];
	t_node		*stack;
	t_stacks	stacks;

	values[0] = 3;
	values[1] = 1;
	values[2] = 2;
	expected[0] = 1;
	expected[1] = 2;
	expected[2] = 3;
	stack = build_stack(values, 3);
	stacks.a = stack;
	stacks.b = NULL;
	sort_small(&stacks);
	assert_stack_values(stacks.a, expected, 3);
	free_stack(stacks.a);
}

static void	set_medium_values(int values[10], int expected[10])
{
	int			i;

	i = 0;
	values[0] = 10;
	values[1] = 5;
	values[2] = 2;
	values[3] = 8;
	values[4] = 4;
	values[5] = 9;
	values[6] = 3;
	values[7] = 7;
	values[8] = 1;
	values[9] = 6;
	expected[0] = 1;
	expected[1] = 2;
	expected[2] = 3;
	expected[3] = 4;
	expected[4] = 5;
	expected[5] = 6;
	expected[6] = 7;
	expected[7] = 8;
	expected[8] = 9;
	expected[9] = 10;
}

static void	test_sort_medium(void)
{
	int			values[10];
	int			expected[10];
	t_node		*stack;
	t_stacks	stacks;

	set_medium_values(values, expected);
	stack = build_stack(values, 10);
	stacks.a = stack;
	stacks.b = NULL;
	sort_medium(&stacks);
	assert_stack_values(stacks.a, expected, 10);
	free_stack(stacks.a);
}

int	main(void)
{
	test_parsing();
	test_swap_and_rotate();
	test_push_and_pop();
	test_sort_small();
	test_sort_medium();
	printf("All push_swap tests passed.\\n");
	return (0);
}
