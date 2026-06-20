/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addufour <addufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 19:00:00 by addufour          #+#    #+#             */
/*   Updated: 2026/06/20 19:00:00 by addufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	print_bench_header(t_config *cfg, int size)
{
	ft_putstr_fd("\n========== BENCH ==========\n", 2);
	ft_putstr_fd("Input size       : ", 2);
	ft_putnbr_fd(size, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("Strategy         : ", 2);
	ft_putstr_fd((char *)strategy_name(cfg->used_strategy), 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("Strategy profile : ", 2);
	ft_putstr_fd((char *)strategy_complexity(cfg->used_strategy), 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("Disorder         : ", 2);
	put_disorder(cfg->disorder);
	ft_putstr_fd("\n", 2);
	if (cfg->used_strategy == ADAPTIVE)
	{
		ft_putstr_fd("Adaptive regime  : ", 2);
		ft_putstr_fd((char *)adaptive_regime(cfg->disorder), 2);
		ft_putstr_fd("\n", 2);
	}
}

static void	print_move(char *name, long val)
{
	ft_putstr_fd(name, 2);
	put_long_fd(val, 2);
	ft_putstr_fd("\n", 2);
}

static void	print_moves_detail(t_bench *bench)
{
	ft_putstr_fd("\n--- Operations detail ---\n", 2);
	print_move("sa  : ", bench->sa);
	print_move("sb  : ", bench->sb);
	print_move("ss  : ", bench->ss);
	print_move("pa  : ", bench->pa);
	print_move("pb  : ", bench->pb);
	print_move("ra  : ", bench->ra);
	print_move("rb  : ", bench->rb);
	print_move("rr  : ", bench->rr);
	print_move("rra : ", bench->rra);
	print_move("rrb : ", bench->rrb);
	print_move("rrr : ", bench->rrr);
}

void	print_bench(t_config *cfg, t_bench *bench, int size)
{
	print_bench_header(cfg, size);
	print_moves_detail(bench);
	ft_putstr_fd("Total operations : ", 2);
	put_long_fd(bench->total, 2);
	ft_putstr_fd("\n===========================\n", 2);
}
