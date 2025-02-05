/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxriimu <sxriimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:07:38 by sberete           #+#    #+#             */
/*   Updated: 2025/02/04 19:02:43 by sxriimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	reverse_rotate(t_stack *stack)
{
	t_node	*new_head;

	if (stack->len < 2)
		return (false);
	new_head = stack->last;
	stack->last = new_head->prev;
	stack->last->next = NULL;
	new_head->next = stack->head;
	stack->head->prev = new_head;
	stack->head = new_head;
	stack->head->prev = NULL;
	return (true);
}

void	reverse_rotate_a(t_stack *a)
{
	if (reverse_rotate(a))
		ft_printf("rra\n");
}

void	reverse_rotate_b(t_stack *b)
{
	if (reverse_rotate(b))
		ft_printf("rrb\n");
}

void	reverse_rotate_rrr(t_stack *a, t_stack *b)
{
	if (reverse_rotate(a) && reverse_rotate(b))
		ft_printf("rrr\n");
}
