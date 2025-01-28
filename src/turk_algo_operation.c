/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_operation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:10:24 by sberete           #+#    #+#             */
/*   Updated: 2025/01/28 18:20:20 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack *stack_a, t_stack *stack_b, t_cost *best_cost)
{
	best_cost->rra = stack_a->len - best_cost->ra;
	best_cost->rrb = stack_b->len - best_cost->rb;
	best_cost->ra = 0;
	best_cost->rb = 0;
	while (best_cost->rra > 0 && best_cost->rrb > 0)
	{
		reverse_rotate_rrr(stack_a, stack_b);
		best_cost->rra--;
		best_cost->rrb--;
	}
}

void	rr(t_stack *stack_a, t_stack *stack_b, t_cost *best_cost)
{
	while (best_cost->ra > 0 && best_cost->rb > 0)
	{
		rotate_rr(stack_a, stack_b);
		best_cost->ra--;
		best_cost->rb--;
	}
}

void	rra(t_stack *stack_a, t_cost *best_cost)
{
	best_cost->rra = stack_a->len - best_cost->ra;
	best_cost->ra = 0;
	while (best_cost->rra > 0)
	{
		reverse_rotate_a(stack_a);
		best_cost->rra--;
	}
}

void	ra(t_stack *stack_a, t_cost *best_cost)
{
	while (best_cost->ra > 0)
	{
		rotate_a(stack_a);
		best_cost->ra--;
	}
}
