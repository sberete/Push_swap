/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxriimu <sxriimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:18:50 by sberete           #+#    #+#             */
/*   Updated: 2025/01/25 17:00:57 by sxriimu          ###   ########.fr       */
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

int	calcul_cost_to_b(t_node *a, t_node *b, int a_value)
{
	int	target;
	int	cost;

	target = search_target_to_b(b, a_value);
	cost = cost_to_top(b, target) + cost_to_top(a, a_value);
	return (cost);
}

t_cost find_best_move(t_stack *a, t_stack *b)
{
	t_cost	cost;

	ft_memset(&cost, 0, sizeof(t_cost));
	return (cost);
}

void	best_move_application(t_stack *stack_a, t_stack *stack_b)
{
	t_cost	best_cost;
	int		cost_a;
	int		cost_b;

	best_cost = find_best_move(stack_a, stack_b);
	
}

void	best_move_application_to_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;
	t_cost	best_cost;
	int		cost_a;
	int		cost_b;

	current = stack_a->head;
	while (current)
	{
		best_cost = find_best_move(current, stack_b->head);
		current = current->next;
	}
}

/*
2 1
3 0
4
9
8
7
11


*/

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

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	size_t	len;

	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	len = stack_a->len;	
	while (len > 3)
	{
		best_move_application_to_b(stack_a, stack_b);
		--len;
	}

}
