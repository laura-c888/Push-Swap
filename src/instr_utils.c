/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchehbi <lchehbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 19:00:00 by lchehbi           #+#    #+#             */
/*   Updated: 2026/06/20 19:00:00 by lchehbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bench_count(t_bench *bench, t_op op)
{
	if (!bench)
		return ;
	if (op == OP_SA)
		bench->sa++;
	else if (op == OP_SB)
		bench->sb++;
	else if (op == OP_SS)
		bench->ss++;
	else if (op == OP_PA)
		bench->pa++;
	else if (op == OP_PB)
		bench->pb++;
	else if (op == OP_RA)
		bench->ra++;
	else if (op == OP_RB)
		bench->rb++;
	else if (op == OP_RR)
		bench->rr++;
	else if (op == OP_RRA)
		bench->rra++;
	else if (op == OP_RRB)
		bench->rrb++;
	else if (op == OP_RRR)
		bench->rrr++;
	bench->total++;
}

void	print_op(const char *operation)
{
	ft_putstr_fd(operation, 1);
}

void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = pop_front(stack);
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	reverse_rotate(t_node **stack)
{
	t_node	*before_last;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	before_last = *stack;
	while (before_last->next->next)
		before_last = before_last->next;
	last = before_last->next;
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
}
