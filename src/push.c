/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 22:25:02 by sberete           #+#    #+#             */
/*   Updated: 2025/01/05 20:52:56 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_node **a, t_node **b)
{
	t_node	*tmp;

	if (!b || !(*b))
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	ft_printf("pa\n");
}

void	push_b(t_node **a, t_node **b)
{
	t_node	*tmp;

	if (!a || !(*a))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	ft_printf("pb\n");
}