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
	ft_memset(&cost, 0, sizeof(t_cost));
	if (pos_a > 0 && pos_b > 0 && pos_a >= (stack_a->len / 2) && pos_b >= (stack_b->len / 2))
	{

		pos_a = stack_a->len - pos_a;
		pos_b = stack_b->len - pos_b;
		if (pos_a > pos_b)
		{
			cost.rrr = pos_b;
			pos_a = pos_a - pos_b;
			pos_b = 0;
		}
		else
		{
			cost.rrr = pos_a;
			pos_b = pos_b - pos_a;
			pos_a = 0;
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

static size_t	min(size_t *a, size_t *b)
{
	size_t	tmp_a;
	size_t	tmp_b;

	tmp_a = *a;
	tmp_b = *b;
	if (tmp_a < tmp_b)
	{
		*b = tmp_b - tmp_a;
		*a = 0;
		return (tmp_a);
	}
	*b = 0;
	*a = tmp_a - tmp_b;
	return (tmp_b);
}

static size_t	max(size_t *a, size_t *b, size_t stack_a_size,
	size_t stack_b_size)
{
	size_t	nb_operations;
	size_t	remaining_a;
	size_t	remaining_b;

	remaining_a = stack_a_size - *a;
	remaining_b = stack_b_size - *b;
	if (remaining_a < remaining_b)
	{
		nb_operations = remaining_a;
		*a = 0;
		*b += nb_operations;
	}
	else
	{
		nb_operations = remaining_b;
		*b = 0;
		*a += nb_operations;
	}
	return (nb_operations);
}

t_cost	calculate_cost_operations(t_stack *stack_a, t_stack *stack_b, size_t position_in_a, size_t position_in_b)
{
	t_cost	operations;
	size_t				half_stack_a_size;
	size_t				half_stack_b_size;

	ft_memset(&operations, 0, sizeof(t_cost));
	half_stack_a_size = stack_a->len / 2;
	half_stack_b_size = stack_b->len / 2;
	if (position_in_a <= half_stack_a_size && position_in_b <= half_stack_b_size
		&& position_in_a > 0 && position_in_b > 0)
		operations.rr = (int)min(&position_in_a, &position_in_b);
	else if (position_in_a >= half_stack_a_size
		&& position_in_b >= half_stack_b_size)
		operations.rrr = (int)max(&position_in_a, &position_in_b,
				stack_a->len, stack_b->len);
	if (position_in_a <= half_stack_a_size)
		operations.ra = (int)position_in_a;
	else if (position_in_a > 0)
		operations.rra = (int)stack_a->len - (int)position_in_a;
	if (position_in_b <= half_stack_b_size)
		operations.rb = (int)position_in_b;
	else if (position_in_b > 0)
		operations.rrb = (int)stack_b->len - (int)position_in_b;
	operations.total = operations.ra + operations.rb + operations.rra
		+ operations.rrb + operations.rr + operations.rrr;
	return (operations);
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
		check = calculate_cost_operations(stack_a, stack_b, (size_t)pos_a, (size_t)pos_b);
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

