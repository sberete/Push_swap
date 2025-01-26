/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxriimu <sxriimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:18:50 by sberete           #+#    #+#             */
/*   Updated: 2025/01/26 17:33:05 by sxriimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void	high_to_top_in_b(t_node **a)
{
	int	high;
	int	cost;

	high = highest_num(*a);
	cost = cost_to_top(*a, high);
	if (cost > ft_lstsize(*a) / 2)
	{
		while ((*a)->value != high)
			reverse_rotate_b(a);
	}
	while ((*a)->value != high)
		rotate_b(a);
}

int	calcul_cost(t_node *a, t_node *b, int b_value)
{
	int	target;
	int	cost;

	target = search_target(a, b_value);
	cost = cost_to_top(a, target) + cost_to_top(b, b_value);
	return (cost);
}

void	best_move_application(t_stack *stack_a, t_stack *stack_b)
{
	t_cost	best_cost;
	int		cost_a;
	int		cost_b;

	best_cost = find_best_move(stack_a, stack_b);
}
*/

t_cost	find_best_move(t_node *stack_a, t_node *stack_b)
{
	t_cost	cost;
	int		target;

	ft_memset(&cost, 0, sizeof(t_cost));
	target = search_target_to_b(stack_b, stack_a->value);
	cost.ra = cost_to_top(stack_b, target);
	cost.rb = cost_to_top(stack_b, stack_b->value);
	cost.total = cost.ra + cost.rb + cost.rra + cost.rrb;
	return (cost);
}
/*
5 6
4 3
0
4
7
11
*/
void	best_move_application_to_b(t_stack *stack_a, t_stack *stack_b)
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
	{
		best_cost.rra = stack_a->len - best_cost.ra;
		best_cost.rrb = stack_b->len - best_cost.rb;
		best_cost.ra = 0;
		best_cost.rb = 0;
		while (best_cost.rra > 0 && best_cost.rrb > 0)
		{
			reverse_rotate_rrr(stack_a, stack_b);
			best_cost.rra--;
			best_cost.rrb--;
		}
	}
	while (best_cost.ra > 0 && best_cost.rb > 0)
	{
		rotate_rr(stack_a, stack_b);
		best_cost.ra--;
		best_cost.rb--;
	}
	if (best_cost.ra > stack_a->len / 2)
	{
		best_cost.rra = stack_a->len - best_cost.ra;
		best_cost.ra = 0;
		while (best_cost.rra > 0)
		{
			reverse_rotate_a(stack_a);
			best_cost.rra--;
		}
	}
	while (best_cost.ra > 0)
	{
		rotate_a(stack_a);
		best_cost.ra--;
	}
	if (best_cost.rb > stack_b->len / 2)
	{
		best_cost.rrb = stack_b->len - best_cost.rb;
		best_cost.rb = 0;
		while (best_cost.rrb > 0)
		{
			reverse_rotate_b(stack_b);
			best_cost.rra--;
		}
	}
	while (best_cost.rb > 0)
	{
		rotate_b(stack_b);
		best_cost.rb--;
	}
	push_b(stack_a, stack_b);
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	size_t	len;

	push_b(stack_b, stack_a);
	push_b(stack_b, stack_a);
	len = stack_a->len;
	while (len > 3)
	{
		best_move_application_to_b(stack_a, stack_b);
		print_stack(stack_a);
		print_stack(stack_b);
		--len;
	}
	if (len == 2)
		sort_two_b(stack_b);
	else if (len == 3)
		sort_three_b(stack_b);
}
