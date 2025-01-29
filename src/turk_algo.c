/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:18:50 by sberete           #+#    #+#             */
/*   Updated: 2025/01/29 18:31:59 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_target_to_b(t_node *stack_b, int b_value)
{
	t_node	*current;
	t_node	*target;

	current = stack_b;
	target = NULL;
	while (current)
	{
		if (current->value < b_value && (target == NULL
				|| current->value > target->value))
			target = current;
		current = current->next;
	}
	if (!target)
		return (cheapest_num(stack_b));
	return (target->value);
}

t_cost	find_best_move_to_b(t_node *stack_a, t_node *stack_b)
{
	t_cost	cost;

	ft_memset(&cost, 0, sizeof(t_cost));
	cost.ra = cost_to_top(stack_b, stack_b->value);
	cost.rb = cost_to_top(stack_a, search_target(stack_b, stack_a->value));
	cost.total = cost.ra + cost.rb;
	return (cost);
}

void	best_move_application_to_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;
	t_cost	best_cost;
	t_cost	check;

	current = stack_b->head;
	best_cost = find_best_move_to_b(current, stack_a->head);
	while (current)
	{
		check = find_best_move(current, stack_b->head);
		if (best_cost.total > check.total)
			best_cost = check;
		current = current->next;
	}
	if (best_cost.ra > stack_a->len / 2 && best_cost.rb > stack_b->len / 2)
		rrr(stack_a, stack_b, &best_cost);
	rr(stack_a, stack_b, &best_cost);
	if (best_cost.ra > stack_a->len / 2)
		rra(stack_a, &best_cost);
	ra(stack_a, &best_cost);
	if (best_cost.rb > stack_b->len / 2)
		rrb(stack_b, &best_cost);
	rb(stack_b, &best_cost);
	push_b(stack_a, stack_b);
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	len;
	int	len_b;

	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	sort_two_b(stack_b);
	len = stack_a->len;
	// while (len > 3)
	// {
		// best_move_application_to_b(stack_a, stack_b);
		// print_stack(stack_a);
		// print_stack(stack_b);
		// --len;
	// }
	if (len == 2)
	{
		sort_two(stack_a);
		//	print_stack(stack_a);
		//	print_stack(stack_b);
	}
	else if (len == 3)
	{
		sort_three(stack_a);
		//	print_stack(stack_a);
		//	print_stack(stack_b);
	}
	len_b = stack_b->len;
	while (len_b > 0)
	{
		best_move_application(stack_a, stack_b);
		// 	print_stack(stack_a);
		//	print_stack(stack_b);
		--len_b;
	}
	cheap_to_top(stack_a);
}
