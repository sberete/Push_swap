/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxriimu <sxriimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:07:38 by sberete           #+#    #+#             */
/*   Updated: 2025/01/17 18:39:07 by sxriimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_node **a, t_node **b, int *cost_a, int *cost_b)
{
	*cost_a = ft_lstsize(*a) - *cost_a;
	*cost_b = ft_lstsize(*b) - *cost_b;
	while (*cost_a > 0 && *cost_b > 0)
	{
		reverse_rotate_rrr(a, b);
		(*cost_a)--;
		(*cost_b)--;
	}
}

void	rr(t_node **a, t_node **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rotate_rr(a, b);
		(*cost_a)--;
		(*cost_b)--;
	}
}

void	rra(t_node **a, int *cost_a)
{
	*cost_a = ft_lstsize(*a) - *cost_a;
	while (*cost_a > 0)
	{
		reverse_rotate_a(a);
		(*cost_a)--;
	}
}

void	rrb(t_node **b, int *cost_b)
{
	*cost_b = ft_lstsize(*b) - *cost_b;
	while (*cost_b > 0)
	{
		reverse_rotate_b(b);
		(*cost_b)--;
	}
}
