/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:07:38 by sberete           #+#    #+#             */
/*   Updated: 2025/01/15 19:59:09 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack *stack)
{
	t_node *tmp;
	if (stack->len < 2)
		return ;
	tmp = stack->head;
	stack->head = stack->last;
	stack->head->next = tmp;
	stack->last = stack->last->prev;
	stack->last->next = NULL;
	stack->head->prev = NULL;
}

void	reverse_rotate_a(t_stack *a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_stack *b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	reverse_rotate_rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
