/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_metric.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addufour <addufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 19:00:00 by addufour          #+#    #+#             */
/*   Updated: 2026/06/20 19:00:00 by addufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	*stack_to_array(t_stack *stack, int size)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (stack)
	{
		arr[i++] = stack->value;
		stack = stack->next;
	}
	return (arr);
}

long	count_total_pairs(int size)
{
	return ((long)size * (size - 1) / 2);
}

long	count_inversions(int *arr, int size)
{
	long	count;
	int		i;
	int		j;

	count = 0;
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

double	compute_disorder(t_stack *stack)
{
	int		*arr;
	int		size;
	long	inversions;
	long	total_pairs;

	size = stack_size(stack);
	if (size < 2)
		return (0.0);
	arr = stack_to_array(stack, size);
	if (!arr)
		return (-1.0);
	inversions = count_inversions(arr, size);
	total_pairs = count_total_pairs(size);
	free(arr);
	return ((double)inversions / (double)total_pairs);
}
