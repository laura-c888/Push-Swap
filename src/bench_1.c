/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addufour <addufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 19:00:00 by addufour          #+#    #+#             */
/*   Updated: 2026/06/20 19:00:00 by addufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	put_long_fd(long n, int fd)
{
	char	c;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
		put_long_fd(n / 10, fd);
	c = (char)((n % 10) + '0');
	write(fd, &c, 1);
}

const char	*strategy_name(t_strategy strategy)
{
	if (strategy == SIMPLE)
		return ("SIMPLE");
	if (strategy == MEDIUM)
		return ("MEDIUM");
	if (strategy == COMPLEX)
		return ("COMPLEX");
	if (strategy == ADAPTIVE)
		return ("ADAPTIVE");
	return ("UNKNOWN");
}

const char	*strategy_complexity(t_strategy strategy)
{
	if (strategy == SIMPLE)
		return ("Optimized for <= 5 elements");
	if (strategy == MEDIUM)
		return ("Chunk-based strategy");
	if (strategy == COMPLEX)
		return ("Radix-based strategy");
	if (strategy == ADAPTIVE)
		return ("Disorder-driven selection");
	return ("Unknown");
}

void	put_disorder(double disorder)
{
	long	value;

	value = (long)(disorder * 1000.0);
	put_long_fd(value / 1000, 2);
	ft_putchar_fd('.', 2);
	ft_putchar_fd((char)((value / 100) % 10) + '0', 2);
	ft_putchar_fd((char)((value / 10) % 10) + '0', 2);
	ft_putchar_fd((char)(value % 10) + '0', 2);
}

const char	*adaptive_regime(double disorder)
{
	if (disorder < LOW_DISORDER)
		return ("LOW (nearly sorted)");
	if (disorder < MEDIUM_DISORDER)
		return ("MEDIUM (partially disordered)");
	return ("HIGH (highly disordered)");
}
