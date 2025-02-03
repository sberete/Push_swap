/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxriimu <sxriimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:07:38 by sberete           #+#    #+#             */
/*   Updated: 2025/02/03 15:15:37 by sxriimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	push(t_stack *receiving_stack, t_stack *giving_stack)
{
	t_node	*node_to_move;

	if (giving_stack->len == 0)
		return (false);
	node_to_move = giving_stack->head;
	giving_stack->head = node_to_move->next;
	if (giving_stack->head)
		giving_stack->head->prev = NULL;
	else
		giving_stack->last = NULL;
	node_to_move->next = receiving_stack->head;
	node_to_move->prev = NULL;
	if (receiving_stack->head)
		receiving_stack->head->prev = node_to_move;
	else
		receiving_stack->last = node_to_move;
	receiving_stack->head = node_to_move;
	receiving_stack->len++;
	giving_stack->len--;
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
		ft_printf("pa\n");
}

void	push_b(t_stack *a, t_stack *b)
{
	if (push(b, a))
		ft_printf("pb\n");
}
