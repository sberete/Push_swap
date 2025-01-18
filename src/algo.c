/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxriimu <sxriimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:18:50 by sberete           #+#    #+#             */
/*   Updated: 2025/01/17 18:37:36 by sxriimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calcul_cost(t_node *a, t_node *b, int b_value)
{
	int	target;
	int	cost;

	target = search_target(a, b_value);
	cost = cost_to_top(a, target) + cost_to_top(b, b_value);
	return (cost);
}

t_node	*find_best_move(t_node *a, t_node *b)
{
	t_node	*best_node;
	t_node	*current;
	int		min_cost;
	int		current_cost;

	best_node = b;
	current = b;
	min_cost = calcul_cost(a, b, b->value);
	while (current)
	{
		current_cost = calcul_cost(a, b, current->value);
		if (current_cost < min_cost)
		{
			min_cost = current_cost;
			best_node = current;
		}
		current = current->next;
	}
	return (best_node);
}

void	best_move_application(t_node **a, t_node **b)
{
	t_node	*best_node;
	int		cost_a;
	int		cost_b;

	best_node = find_best_move(*a, *b);
	cost_a = cost_to_top(*a, search_target(*a, best_node->value));
	cost_b = cost_to_top(*b, best_node->value);
	ft_printf("%d, %d, %d, %d\n", best_node->value, search_target(*a,
			best_node->value), cost_b, cost_a);
	if (cost_a > ft_lstsize(*a) / 2 && cost_b > ft_lstsize(*b) / 2)
		rrr(a, b, &cost_a, &cost_b);
	rr(a, b, &cost_a, &cost_b);
	if (cost_a > ft_lstsize(*a) / 2)
		rra(a, &cost_a);
	ra(a, &cost_a);
	if (cost_b > ft_lstsize(*b) / 2)
		rrb(b, &cost_b);
	rb(b, &cost_b);
	push_a(a, b);
}

void	cheap_to_top(t_node **a)
{
	int	cheap;
	int	cost;

	cheap = cheapest_num(*a);
	cost = cost_to_top(*a, cheap);
	if (cost > ft_lstsize(*a) / 2)
	{
		while ((*a)->value != cheap)
			reverse_rotate_a(a);
	}
	while ((*a)->value != cheap)
		rotate_a(a);
}

void	sort_stack(t_node **a, t_node **b)
{
	push_to_b(a, b);
	sort_three(a);
	while (*b)
	{
		best_move_application(a, b);
		print_stack(*a);
		print_stack(*b);
	}
	cheap_to_top(a);
}
