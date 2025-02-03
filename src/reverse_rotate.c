/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:07:38 by sberete           #+#    #+#             */
/*   Updated: 2025/01/28 19:42:41 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	reverse_rotate(t_stack *stack)
{
	t_node	*current;
	t_node	*tail;

	if (stack->len < 2)
		return (false);
	current = stack->head;
	tail = stack->last;
	while (current->next != tail)
		current = current->next;
	stack->last->next = stack->head;
	stack->head = stack->last;
	current->next = NULL;
	stack->last = current;
	return (true);
}

void	reverse_rotate_a(t_stack *a)
{
	if(reverse_rotate(a))
		printf("rra\n");
}

void	reverse_rotate_b(t_stack *b)
{
	if(reverse_rotate(b))
		printf("rrb\n");
}

void	reverse_rotate_rrr(t_stack *a, t_stack *b)
{
	if (reverse_rotate(a) && reverse_rotate(b))
		printf("rrr\n");
}
