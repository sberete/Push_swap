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

static bool	push(t_stack *receiving_stack, t_stack *giving_stack)
{
		t_node	*new_head;

	if (giving_stack->len == 0 || receiving_stack == giving_stack)
		return (false);
	new_head = giving_stack -> head -> next;
	giving_stack -> head -> next = receiving_stack -> head;
	receiving_stack -> head = giving_stack -> head;
	giving_stack -> head = new_head;
	giving_stack->len--;
	receiving_stack->len++;
	if (receiving_stack->len == 1)
		receiving_stack->last = receiving_stack->head;
	else if (giving_stack->len == 0)
		giving_stack->last = NULL;
	return (true);
}


/*
1 2
7 8

7 1
  2
  8  
*/
void	push_a(t_stack *a, t_stack *b)
{
	if (push(a, b))
		printf("pa\n");
}

void	push_b(t_stack *a, t_stack *b)
{
	if (push(b, a))
		printf("pb\n");
}
