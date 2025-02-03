/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_utils_suite.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:26:24 by sberete           #+#    #+#             */
/*   Updated: 2025/01/29 15:02:49 by sberete          ###   ########.fr       */
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

int	cheapest_num(t_node *node)
{
	int	cheap;
	int	pos;
	int	min_pos;

	cheap = node->value;
	pos = 0;
	min_pos = 0;
	while (node)
	{
		if (cheap > node->value)
		{
			cheap = node->value;
			min_pos = pos;
		}
		node = node->next;
		++pos;
	}
	return (min_pos);
}

int	highest_num(t_node *node)
{
	int	high;
	int	pos;
	int	max_pos;

	high = node->value;
	pos = 0;
	max_pos = 0;
	while (node)
	{
		if (high < node->value)
		{
			high = node->value;
			max_pos = pos;
		}
		node = node->next;
		++pos;
	}
	return (max_pos);
}
