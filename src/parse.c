/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchehbi <lchehbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 19:00:00 by lchehbi           #+#    #+#             */
/*   Updated: 2026/06/20 19:00:00 by lchehbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	parse_token(t_node **stack, const char **cursor)
{
	long	value;

	value = parse_number(cursor);
	if (**cursor != '\0' && !is_space(**cursor))
		error_exit("Error");
	if (duplicate_value(*stack, (int)value))
		error_exit("Error");
	push_bottom(stack, new_node((int)value));
}

static void	parse_string(t_node **stack, const char *arg)
{
	const char	*cursor;
	bool		has_token;

	cursor = arg;
	has_token = false;
	skip_spaces(&cursor);
	while (*cursor)
	{
		parse_token(stack, &cursor);
		has_token = true;
		skip_spaces(&cursor);
	}
	if (!has_token)
		error_exit("Error");
}

static void	fill_indices(t_node *stack, int *vals, int size)
{
	int		i;
	t_node	*cur;

	cur = stack;
	while (cur)
	{
		i = 0;
		while (i < size && vals[i] != cur->value)
			i++;
		cur->index = i;
		cur = cur->next;
	}
}

void	assign_indices(t_node *stack)
{
	int		*vals;
	int		i;
	int		size;
	t_node	*cur;

	size = stack_size(stack);
	vals = malloc(sizeof(int) * size);
	if (!vals)
		error_exit("Error");
	cur = stack;
	i = -1;
	while (++i < size && cur)
	{
		vals[i] = cur->value;
		cur = cur->next;
	}
	qsort(vals, size, sizeof(int), compare_ints);
	fill_indices(stack, vals, size);
	free(vals);
}

t_node	*parse_arguments(int argc, char **argv)
{
	t_node	*stack;
	int		i;

	stack = NULL;
	if (argc < 2)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		if (!argv[i][0])
			error_exit("Error");
		parse_string(&stack, argv[i]);
		i++;
	}
	if (!stack)
		error_exit("Error");
	return (stack);
}
