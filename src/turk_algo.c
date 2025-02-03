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

/*
4 1
8 2
5
*/

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



void	execute(t_cost best_cost, t_stack *stack_a, t_stack *stack_b)
{
	while (best_cost.ra-- > 0)
		rotate_a(stack_a);
	while (best_cost.rb-- > 0)
		rotate_b(stack_b);
	while (best_cost.rra-- > 0)
		reverse_rotate_a(stack_a);
	while (best_cost.rrb-- > 0)
		reverse_rotate_b(stack_b);
	while (best_cost.rr-- > 0)
		rotate_rr(stack_a, stack_b);
	while (best_cost.rrr-- > 0)
		reverse_rotate_rrr(stack_a, stack_b);
}

t_cost get_cost(t_stack *stack_a, t_stack *stack_b, size_t pos_a, size_t pos_b)
{
	t_cost cost;
	size_t len_a;
	size_t len_b;
	ft_memset(&cost, 0, sizeof(t_cost));
	if (pos_a > 0 && pos_b > 0 && pos_a >= (stack_a->len / 2) && pos_b >= (stack_b->len / 2))
	{
		len_a = stack_a->len - pos_a;
		len_b = stack_b->len - pos_b;
		if (len_a < len_b)
		{
			cost.rrr = len_a;
			pos_b += len_a;
			pos_a = 0;
		}
		else
		{
			cost.rrr = len_b;
			pos_a += len_b;
			pos_b = 0;
		}

	}
	else if (pos_a > 0 && pos_b > 0 && pos_a < (stack_a->len / 2) && pos_b < (stack_b->len / 2))
	{
		if (pos_a > pos_b)
		{
			cost.rr = pos_b;
			pos_a = pos_a - pos_b;
			pos_b = 0;
		}
		else
		{
			cost.rr = pos_a;
			pos_b = pos_b - pos_a;
			pos_a = 0;
		}
	}
	if (pos_a > stack_a->len / 2)
		cost.rra = stack_a->len - pos_a;
	else
		cost.ra = pos_a;
	if (pos_b > stack_b->len / 2)
		cost.rrb = stack_b->len - pos_b;
	else
		cost.rb = pos_b;
	cost.total = cost.ra + cost.rra + cost.rb + cost.rrb + cost.rr + cost.rrr;
	return (cost);
}

void	best_move_application_to_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;
	t_cost	best_cost;
	t_cost	check;
	int		pos_a;
	int		pos_b;

	current = stack_a->head;
	best_cost.total = (size_t)-1;
	pos_a = 0;
	while (current)
	{
		pos_b = search_target_to_b(stack_b->head, current->value);
		check = get_cost(stack_a, stack_b, (size_t)pos_a, (size_t)pos_b);
		if (best_cost.total > check.total)
			best_cost = check;
		if (best_cost.total == 0)
			break;
		++pos_a;
		current = current->next;
	}
	execute(best_cost, stack_a, stack_b);
	push_b(stack_a, stack_b);
}

void	best_move_application_to_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;
	t_cost	best_cost;
	t_cost	check;
	int		pos_a;
	int		pos_b;

	current = stack_b->head;
	best_cost.total = (size_t)-1;
	pos_b = 0;
	while (current)
	{
		pos_a = search_target_to_a(stack_a->head, current->value);
		check = get_cost(stack_a, stack_b, (size_t)pos_a, (size_t)pos_b);
		if (best_cost.total > check.total)
			best_cost = check;
		if (best_cost.total == 0)
			break;
		++pos_b;
		current = current->next;
	}
	execute(best_cost, stack_a, stack_b);
	push_a(stack_a, stack_b);
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

// 4676