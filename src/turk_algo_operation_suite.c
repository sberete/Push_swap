/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_operation_suite.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:22:04 by sberete           #+#    #+#             */
/*   Updated: 2025/01/28 18:20:13 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_stack *stack_b, t_cost *best_cost)
{
	best_cost->rrb = stack_b->len - best_cost->rb;
	best_cost->rb = 0;
	while (best_cost->rrb > 0)
	{
		reverse_rotate_b(stack_b);
		best_cost->rra--;
	}
}

void	rb(t_stack *stack_b, t_cost *best_cost)
{
	while (best_cost->rb > 0)
	{
		rotate_b(stack_b);
		best_cost->rb--;
	}
}
