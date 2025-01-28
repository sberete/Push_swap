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

static void	rotate(t_stack *stack)
{
	t_node	*new_last;

	if (stack->len < 2)
		return ;
	new_last = stack->head;
	stack->head = stack->head->next;
	new_last->next = NULL;
	stack->last->next = new_last;
	stack->last = new_last;
}

void	rotate_a(t_stack *a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rotate_b(t_stack *b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rotate_rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
