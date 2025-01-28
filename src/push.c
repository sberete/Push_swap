/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:07:38 by sberete           #+#    #+#             */
/*   Updated: 2025/01/28 19:42:33 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *receiving_stack, t_stack *giving_stack)
{
	t_node	*new_receiveng_stack_head;

	if (giving_stack->len == 0)
		return ;
	new_receiveng_stack_head = giving_stack->head;
	giving_stack->head = giving_stack->head->next;
	new_receiveng_stack_head->next = receiving_stack->head;
	receiving_stack->head = new_receiveng_stack_head;
	if (receiving_stack->len == 0)
		receiving_stack->last = new_receiveng_stack_head;
	receiving_stack->len++;
	giving_stack->len--;
}

void	push_a(t_stack *a, t_stack *b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	push_b(t_stack *a, t_stack *b)
{
	push(b, a);
	ft_printf("pb\n");
}
