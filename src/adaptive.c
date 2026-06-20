/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addufour <addufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 19:00:00 by addufour          #+#    #+#             */
/*   Updated: 2026/06/20 19:00:00 by addufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_strategy	choose_strategy(int size, double disorder)
{
	if (size <= 5)
		return (SIMPLE);
	if (disorder < LOW_DISORDER)
		return (ADAPTIVE);
	if (disorder < MEDIUM_DISORDER)
		return (MEDIUM);
	return (COMPLEX);
}

static void	execute_simple_ad(t_stack **a, t_stack **b, t_config *cfg)
{
	(void)cfg;
	mini_sort(a, b, NULL);
}

static void	execute_medium_ad(t_stack **a, t_stack **b, t_config *cfg)
{
	(void)cfg;
	assign_indexes(*a);
	chunk_sort(a, b);
}

static void	execute_complex_ad(t_stack **a, t_stack **b, t_config *cfg)
{
	(void)cfg;
	assign_indexes(*a);
	radix_sort(a, b, NULL);
}

void	adaptive_sort(t_stack **a, t_stack **b, t_config *cfg)
{
	int	size;

	if (!a || !*a || !cfg)
		return ;
	size = stack_size(*a);
	cfg->used_strategy = choose_strategy(size, cfg->disorder);
	if (cfg->used_strategy == SIMPLE)
		execute_simple_ad(a, b, cfg);
	else if (cfg->used_strategy == ADAPTIVE)
		nearly_sorted_sort(a);
	else if (cfg->used_strategy == MEDIUM)
		execute_medium_ad(a, b, cfg);
	else
		execute_complex_ad(a, b, cfg);
}
