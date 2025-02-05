/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxriimu <sxriimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:26:24 by sberete           #+#    #+#             */
/*   Updated: 2025/02/05 20:23:40 by sxriimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack)
{
	int	first;
	int	second;

	first = stack->head->value;
	second = stack->head->next->value;
	if (first > second)
		swap_a(stack);
	else
		return ;
}

void	sort_three(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	first = stack->head->value;
	second = stack->head->next->value;
	third = stack->head->next->next->value;
	if (first > second && first > third)
		rotate_a(stack);
	else if (second > first && second > third)
		reverse_rotate_a(stack);
	sort_two(stack);
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	len;

	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	len = stack_a->len;
	while (len > 3)
	{
		best_move_application_to_b(stack_a, stack_b);
		--len;
	}
	if (len == 2)
		sort_two(stack_a);
	else
		sort_three(stack_a);
	len = stack_b->len;
	while (len > 0)
	{
		best_move_application_to_a(stack_a, stack_b);
		--len;
	}
	cheap_to_top(stack_a);
}
