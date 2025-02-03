/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:07:38 by sberete           #+#    #+#             */
/*   Updated: 2025/01/15 20:47:30 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	printf("sa\n");
}

void	swap_b(t_node **b)
{
	swap(*b);
	printf("sb\n");
}

void	swap_ss(t_node **a, t_node **b)
{
	swap(*a);
	swap(*b);
	printf("ss\n");
}
