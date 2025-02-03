/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxriimu <sxriimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:07:38 by sberete           #+#    #+#             */
/*   Updated: 2025/02/03 15:17:53 by sxriimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (stack->len < 2)
		return (false);
	first = stack->head;
	second = stack->head->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	stack->head = second;
	if (stack->len == 2)
		stack->last = first;
	return (true);
}


void	swap_a(t_stack *a)
{
	if (swap(a))
		printf("sa\n");
}

void	swap_b(t_stack *b)
{
	if (swap(b))
		printf("sb\n");
}

void	swap_ss(t_stack *a, t_stack *b)
{
	if (swap(a) && swap(b))
		printf("ss\n");
}
