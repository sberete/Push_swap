/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:07:38 by sberete           #+#    #+#             */
/*   Updated: 2025/01/28 19:42:46 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool rotate(t_stack *stack)
{
	t_node	*head;
	t_node	*tail;

	if (stack->len < 2)
		return (false);
	head = stack->head;
	tail = stack->last;
	head->prev = tail;
	stack->head = head->next;
	stack->head->prev = NULL;
	head->next = NULL;
	tail->next = head;
	stack->last = head;
	return (true);
}

void	rotate_a(t_stack *a)
{
	if (rotate(a))
		ft_printf("ra\n");
}

void	rotate_b(t_stack *b)
{
	if (rotate(b))
		ft_printf("rb\n");
}

void	rotate_rr(t_stack *a, t_stack *b)
{
	if (rotate(a) && rotate(b))
		ft_printf("rr\n");
}
