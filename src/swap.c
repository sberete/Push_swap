/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:07:38 by sberete           #+#    #+#             */
/*   Updated: 2025/01/28 19:42:58 by sberete          ###   ########.fr       */
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
	second = first->next;
	stack->head = second;
	first->next = second->next;
	if (stack->len > 2)
		second->next->prev = first;
	second->next = first;
	first->prev = second;
	second->prev = NULL;
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
