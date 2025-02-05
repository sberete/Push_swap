/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxriimu <sxriimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:43:27 by sberete           #+#    #+#             */
/*   Updated: 2025/02/05 21:59:49 by sxriimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
		return ;
	}
	while (pos)
	{
		rotate_a(stack);
		--pos;
	}
}

int	search_target_to_b(t_node *node_b, int a_value)
{
	t_node	*current;
	size_t	target_node_index;
	size_t	position;
	int		b_node_value;

	current = node_b;
	position = 0;
	target_node_index = (size_t)-1;
	b_node_value = INT_MIN;
	while (current != NULL)
	{
		if (a_value > current->value && current->value > b_node_value)
		{
			target_node_index = position;
			b_node_value = current->value;
		}
		++position;
		current = current->next;
	}
	if (target_node_index == (size_t)-1)
		return (highest_num(node_b));
	return (target_node_index);
}

int	search_target_to_a(t_node *node_a, int b_value)
{
	t_node	*current;
	size_t	target_node_index;
	size_t	position;
	int		a_node_value;

	current = node_a;
	position = 0;
	a_node_value = INT_MAX;
	target_node_index = (size_t)-1;
	while (current != NULL)
	{
		if (current->value > b_value && current->value < a_node_value)
		{
			target_node_index = position;
			a_node_value = current->value;
		}
		++position;
		current = current->next;
	}
	if (target_node_index == (size_t)-1)
		return (cheapest_num(node_a));
	return (target_node_index);
}
