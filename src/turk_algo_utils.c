/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:43:27 by sberete           #+#    #+#             */
/*   Updated: 2025/01/29 17:35:41 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	cost_to_top(t_node *stack, int value)
{
	t_node	*temp_stack;
	size_t		index;

	temp_stack = stack;
	index = 0;
	while (temp_stack && temp_stack->value != value)
	{
		index++;
		temp_stack = temp_stack->next;
	}
	return (index);
}

int	search_target(t_node *stack_a, int b_value)
{
	t_node	*current;
	t_node	*target;

	current = stack_a;
	target = NULL;
	while (current)
	{
		if (current->value > b_value && (target == NULL
				|| current->value < target->value))
			target = current;
		current = current->next;
	}
	if (target == NULL)
		return (cheapest_num(stack_a));
	return (target->value);
}

void	cheap_to_top(t_stack *stack)
{
	int	cheap;
	size_t	cost;

	cheap = cheapest_num(stack->head);
	cost = cost_to_top(stack->head, cheap);
	ft_printf("%d\n", cost);
	if (cost > stack->len / 2)
	{
		while (stack->head->value != cheap)
			reverse_rotate_a(stack);
	}
	while (stack->head->value != cheap)
		rotate_a(stack);
}

t_cost	find_best_move(t_node *stack_a, t_node *stack_b)
{
	t_cost	cost;

	ft_memset(&cost, 0, sizeof(t_cost));
	cost.ra = cost_to_top(stack_a, search_target(stack_a, stack_b->value));
	cost.rb = cost_to_top(stack_b, stack_b->value);
	cost.total = cost.ra + cost.rb;
	return (cost);
}

void	best_move_application(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;
	t_cost	best_cost;
	t_cost	check;

	current = stack_a->head;
	best_cost = find_best_move(current, stack_b->head);
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
	push_a(stack_a, stack_b);
}