/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxriimu <sxriimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:23:53 by sxriimu           #+#    #+#             */
/*   Updated: 2025/02/05 20:23:54 by sxriimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	calculate_rrr(size_t *pos_a, size_t *pos_b, t_stack *stack_a,
		t_stack *stack_b)
{
	size_t	len_a;
	size_t	len_b;
	size_t	rrr;

	len_a = stack_a->len - *pos_a;
	len_b = stack_b->len - *pos_b;
	if (len_a < len_b)
	{
		rrr = len_a;
		*pos_a = 0;
		*pos_b += len_a;
	}
	else
	{
		rrr = len_b;
		*pos_a += len_b;
		*pos_b = 0;
	}
	return (rrr);
}

void	calculate_rr(t_cost *cost, size_t *pos_a, size_t *pos_b)
{
	if (*pos_a < *pos_b)
	{
		cost->rr = *pos_a;
		*pos_b -= *pos_a;
		*pos_a = 0;
	}
	else
	{
		cost->rr = *pos_b;
		*pos_a -= *pos_b;
		*pos_b = 0;
	}
}

t_cost	get_cost(t_stack *stack_a, t_stack *stack_b, size_t pos_a, size_t pos_b)
{
	t_cost	cost;

	ft_memset(&cost, 0, sizeof(t_cost));
	if (pos_a > 0 && pos_b > 0 && pos_a >= (stack_a->len / 2)
		&& pos_b >= (stack_b->len / 2))
		cost.rrr = calculate_rrr(&pos_a, &pos_b, stack_a, stack_b);
	else if (pos_a > 0 && pos_b > 0 && pos_a < (stack_a->len / 2)
		&& pos_b < (stack_b->len / 2))
		calculate_rr(&cost, &pos_a, &pos_b);
	if (pos_a > stack_a->len / 2)
		cost.rra = stack_a->len - pos_a;
	else
		cost.ra = pos_a;
	if (pos_b > stack_b->len / 2)
		cost.rrb = stack_b->len - pos_b;
	else
		cost.rb = pos_b;
	cost.total = cost.ra + cost.rra + cost.rb + cost.rrb + cost.rr + cost.rrr;
	return (cost);
}
