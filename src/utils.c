/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxriimu <sxriimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:07:38 by sberete           #+#    #+#             */
/*   Updated: 2025/01/25 15:53:26 by sxriimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_node *lst)
{
	t_node	*count;
	int		i;

	i = 1;
	if (!lst)
		return (0);
	count = lst->next;
	while (count)
	{
		count = count->next;
		i++;
	}
	return (i);
}

int	cheapest_num(t_node *stack)
{
	int	cheap;

	cheap = stack->value;
	while (stack)
	{
		if (cheap > stack->value)
			cheap = stack->value;
		stack = stack->next;
	}
	return (cheap);
}

int	highest_num(t_node *stack)
{
	int	high;

	high = stack->value;
	while (stack)
	{
		if (high < stack->value)
			high = stack->value;
		stack = stack->next;
	}
	return (high);
}

void	ra(t_node **a, int *cost_a)
{
	while (*cost_a > 0)
	{
		rotate_a(a);
		(*cost_a)--;
	}
}

void	rb(t_node **b, int *cost_b)
{
	while (*cost_b > 0)
	{
		rotate_b(b);
		(*cost_b)--;
	}
}
