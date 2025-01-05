/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 22:25:44 by sberete           #+#    #+#             */
/*   Updated: 2025/01/05 20:52:21 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node *ap)
{
	int	tmp;

	if (!ap || !(ap->next))
		return ;
	tmp = ap->value;
	ap->value = ap->next->value;
	ap->next->value = tmp;
}

void	swap_a(t_node **a)
{
	swap(*a);
	ft_printf("sa\n");
}

void	swap_b(t_node **b)
{
	swap(*b);
	ft_printf("sb\n");
}

void	swap_ss(t_node **a, t_node **b)
{
	swap(*a);
	swap(*b);
	ft_printf("ss\n");
}
