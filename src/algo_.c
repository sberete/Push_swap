/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxriimu <sxriimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:26:24 by sberete           #+#    #+#             */
/*   Updated: 2025/01/25 15:40:46 by sxriimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_node **a, t_node **b)
{
	while (ft_lstsize(*a) > 3)
		push_b(a, b);
}

void	sort_two(t_node **a)
{
	int	first;
	int	second;

	first = (*a)->value;
	second = (*a)->next->value;
	if (first > second)
		swap_a(a);
	else
		return ;
}

void	sort_three(t_node **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && first > third)
		rotate_a(a);
	else if (second > first && second > third)
		reverse_rotate_a(a);
	sort_two(a);
}

int	cost_to_top(t_node *stack, int value)
{
	t_node	*temp_stack;
	int		index;

	temp_stack = stack;
	index = 0;
	while (temp_stack && temp_stack->value != value)
	{
		index++;
		temp_stack = temp_stack->next;
	}
	return (index);
}

int	search_target(t_node *a, int b_value)
{
	t_node	*current;
	t_node	*target;

	current = a;
	target = NULL;
	while (current)
	{
		if (current->value > b_value && (target == NULL
				|| current->value < target->value))
			target = current;
		current = current->next;
	}
	if (!target)
		return (cheapest_num(a));
	return (target->value);
}

int	search_target_to_b(t_node *b, int b_value)
{
	t_node	*current;
	t_node	*target;

	current = b;
	target = NULL;
	while (current)
	{
		if (current->value < b_value && (target == NULL
				|| current->value > target->value))
			target = current;
		current = current->next;
	}
	if (!target)
		return (highest_num(b));
	return (target->value);
}