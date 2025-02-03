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
	size_t	pos;

	pos = cheapest_num(stack->head);
	if (pos > stack->len / 2)
	{
		pos = stack->len - pos;
		while (pos)
		{
			reverse_rotate_a(stack);
			--pos;
		}
		return;
	}
	while (pos)
	{
		rotate_a(stack);
		--pos;
	}
}

