/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchehbi <lchehbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 19:00:00 by lchehbi           #+#    #+#             */
/*   Updated: 2026/06/20 19:00:00 by lchehbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **a, t_node **b)
{
	t_node	*node;

	node = pop_front(b);
	if (!node)
		return ;
	push_front(a, node);
	print_op("pa\n");
}

void	pb(t_node **a, t_node **b)
{
	t_node	*node;

	node = pop_front(a);
	if (!node)
		return ;
	push_front(b, node);
	print_op("pb\n");
}
