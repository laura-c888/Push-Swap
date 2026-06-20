/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchehbi <lchehbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 00:00:00 by lchehbi           #+#    #+#             */
/*   Updated: 2026/06/20 18:00:00 by lchehbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

/* ---- Constantes ---- */

# define LOW_DISORDER    0.2
# define MEDIUM_DISORDER 0.5

/* ---- Types ---- */

typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_strategy;

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef t_node	t_stack;

typedef struct s_stacks
{
	t_node	*a;
	t_node	*b;
}	t_stacks;

typedef struct s_bench
{
	long	sa;
	long	sb;
	long	ss;
	long	pa;
	long	pb;
	long	ra;
	long	rb;
	long	rr;
	long	rra;
	long	rrb;
	long	rrr;
	long	total;
}	t_bench;

typedef struct s_config
{
	t_strategy	strategy;
	t_strategy	used_strategy;
	double		disorder;
	int			bench;
}	t_config;

typedef enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR
}	t_op;

/* ---- ft_utils ---- */

int			ft_strcmp(const char *s1, const char *s2);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(const char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

/* ---- stack (stack.c) ---- */

void		error_exit(const char *message);
t_node		*new_node(int value);
void		free_stack(t_node *stack);
int			stack_size(t_node *stack);
bool		stack_sorted(t_node *stack);
void		push_front(t_node **stack, t_node *node);
void		push_bottom(t_node **stack, t_node *node);
t_node		*pop_front(t_node **stack);
t_node		*stack_last(t_node *stack);
t_node		*stack_before_last(t_node *stack);
void		print_stack(const char *name, t_node *stack);

/* ---- parse (parse.c) ---- */

t_node		*parse_arguments(int argc, char **argv);
void		assign_indices(t_node *stack);

/* ---- utils (from multiple files) ---- */

bool		is_space(char c);
void		skip_spaces(const char **str);
long		parse_number(const char **str);
bool		duplicate_value(t_node *stack, int value);
int			compare_ints(const void *a, const void *b);
void		put_long_fd(long n, int fd);
void		put_disorder(double disorder);
const char	*adaptive_regime(double disorder);
int			find_max_position(t_node *stack);
void		rotate_to_closest_in_chunk(t_node **a, int limit);
void		push_chunks_to_b(t_stacks *stacks, int chunk_size);
void		restore_b_to_a(t_stacks *stacks);
void		exec_rotations(t_node **a, int top_pos, int bot_pos);
int			find_min_position(t_node *stack);
void		rotate_to_top(t_node **stack, int position);
int			*copy_values(t_stack *a);
void		sort_array(int *arr, int size);
int			find_index(int *sorted, int size, int value);
void		push_chunks_to_b2(t_stack **a, t_stack **b, int chunk_size);
void		print_op(const char *operation);

/* ---- instructions (instructions.c) ---- */

void		bench_count(t_bench *bench, t_op op);
void		swap(t_node **stack);
void		rotate(t_node **stack);
void		reverse_rotate(t_node **stack);
void		sa(t_node **a);
void		sb(t_node **b);
void		ss(t_node **a, t_node **b);
void		pa(t_node **a, t_node **b);
void		pb(t_node **a, t_node **b);
void		ra(t_node **a);
void		rb(t_node **b);
void		rr(t_node **a, t_node **b);
void		rra(t_node **a);
void		rrb(t_node **b);
void		rrr(t_node **a, t_node **b);

/* ---- sort_simple (sort_simple.c) ---- */

void		sort_small(t_stacks *stacks);
void		sort_medium(t_stacks *stacks);

/* ---- mini_sort (mini_sort.c) ---- */

int			find_min_pos(t_stack *a);
int			is_sorted(t_stack *a);
void		move_min_to_top(t_stack **a);
void		sort_two(t_stack **a);
void		sort_three(t_stack **a);
void		sort_four(t_stack **a, t_stack **b);
void		sort_five(t_stack **a, t_stack **b);
void		mini_sort(t_stack **a, t_stack **b, t_bench *bench);

/* ---- disorder_metric (disorder_metric.c) ---- */

int			*stack_to_array(t_stack *stack, int size);
long		count_total_pairs(int size);
long		count_inversions(int *arr, int size);
double		compute_disorder(t_stack *stack);

/* ---- nearly_sorted (nearly_sorted.c) ---- */

void		nearly_sorted_sort(t_stack **a);

/* ---- chunksort (chunksort.c) ---- */

void		chunk_sort(t_stack **a, t_stack **b);

/* ---- radix (radix.c) ---- */

void		assign_indexes(t_stack *a);
int			stack_max_index(t_stack *a);
int			get_max_bits(t_stack *a);
void		radix_sort(t_stack **a, t_stack **b, t_bench *bench);

/* ---- adaptive (adaptive.c) ---- */

t_strategy	choose_strategy(int size, double disorder);
void		adaptive_sort(t_stack **a, t_stack **b, t_config *cfg);

/* ---- bench (bench.c) ---- */

const char	*strategy_name(t_strategy strategy);
const char	*strategy_complexity(t_strategy strategy);
void		print_bench(t_config *cfg, t_bench *bench, int size);

/* ---- flags (flags.c) ---- */

void		init_config(t_config *cfg);
int			parse_flag(char *arg, t_config *cfg);
void		run_strategy(t_stack **a, t_stack **b, t_config *cfg);

#endif
