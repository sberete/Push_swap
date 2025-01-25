/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxriimu <sxriimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:26:24 by sberete           #+#    #+#             */
/*   Updated: 2025/01/25 15:40:46 by sxriimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_node **a, t_node **b)
{
	while (ft_lstsize(*a) > 3)
		push_b(a, b);
}

void	sort_two(t_node **a)
{
	int	first;
	int	second;

	first = (*a)->value;
	second = (*a)->next->value;
	if (first > second)
		swap_a(a);
	else
		return ;
}

void	sort_three(t_node **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && first > third)
		rotate_a(a);
	else if (second > first && second > third)
		reverse_rotate_a(a);
	sort_two(a);
}

