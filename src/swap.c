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

static void	swap(t_stack *ap)
{
	t_node	*tmp;

	if (!ap)
		return ;
	tmp = ap->head;
	ap->head = ap->head->next;
	ap->head->next = tmp;
}

void	swap_a(t_stack *a)
{
	swap(a);
	ft_printf("sa\n");
}

void	swap_b(t_stack *b)
{
	swap(b);
	ft_printf("sb\n");
}

void	swap_ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
