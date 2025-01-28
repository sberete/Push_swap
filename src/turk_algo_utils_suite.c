/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_utils_suite.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:26:24 by sberete           #+#    #+#             */
/*   Updated: 2025/01/28 18:20:27 by sberete          ###   ########.fr       */
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

void	sort_two_b(t_stack *stack)
{
	int	first;
	int	second;

	first = stack->head->value;
	second = stack->head->next->value;
	if (first < second)
		swap_b(stack);
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

int	cheapest_num(t_node *stack)
{
	int	cheap;

	cheap = stack->value;
	while (stack)
	{
		if (cheap > stack->value)
			cheap = stack->value;
		stack = stack->next;
	}
	return (cheap);
}

int	highest_num(t_node *stack)
{
	int	high;

	high = stack->value;
	while (stack)
	{
		if (high < stack->value)
			high = stack->value;
		stack = stack->next;
	}
	return (high);
}
