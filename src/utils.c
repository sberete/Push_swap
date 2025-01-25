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
