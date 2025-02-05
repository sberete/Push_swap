/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_move_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxriimu <sxriimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:18:50 by sberete           #+#    #+#             */
/*   Updated: 2025/02/05 22:00:33 by sxriimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
			break ;
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
			break ;
		++pos_b;
		current = current->next;
	}
	execute(best_cost, stack_a, stack_b);
	push_a(stack_a, stack_b);
}
