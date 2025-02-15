/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxriimu <sxriimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:07:38 by sberete           #+#    #+#             */
/*   Updated: 2025/02/05 21:31:45 by sxriimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static bool	rotate(t_stack *stack)
{
	t_node	*new_last;

	if (stack->len < 2)
		return (false);
	new_last = stack->head;
	stack->head = new_last->next;
	stack->head->prev = NULL;
	stack->last->next = new_last;
	new_last->prev = stack->last;
	new_last->next = NULL;
	stack->last = new_last;
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
