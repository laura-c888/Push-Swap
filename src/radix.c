/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addufour <addufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 19:00:00 by addufour          #+#    #+#             */
/*   Updated: 2026/06/20 19:00:00 by addufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	stack_max_index(t_stack *a)
{
	int	max;

	max = 0;
	while (a)
	{
		if (a->index > max)
			max = a->index;
		a = a->next;
	}
	return (max);
}

int	get_max_bits(t_stack *a)
{
	int	max;
	int	bits;

	max = stack_max_index(a);
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

static void	process_bit(t_stacks *sts, int bit, int size, t_bench *bench)
{
	int	i;

	if (!sts->a)
		return ;
	i = 0;
	while (i < size)
	{
		if (((sts->a)->index >> bit) & 1)
		{
			ra(&sts->a);
			bench_count(bench, OP_RA);
		}
		else
		{
			pb(&sts->a, &sts->b);
			bench_count(bench, OP_PB);
		}
		i++;
	}
}

static void	restore_stack(t_stacks *sts, t_bench *bench)
{
	while (sts->b)
	{
		pa(&sts->a, &sts->b);
		bench_count(bench, OP_PA);
	}
}

void	radix_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int			max_bits;
	int			size;
	int			bit;
	t_stacks	sts;

	sts.a = *a;
	sts.b = *b;
	size = stack_size(*a);
	max_bits = get_max_bits(*a);
	bit = 0;
	while (bit < max_bits)
	{
		process_bit(&sts, bit, size, bench);
		restore_stack(&sts, bench);
		bit++;
	}
	*a = sts.a;
	*b = sts.b;
}
