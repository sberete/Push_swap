/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:07:38 by sberete           #+#    #+#             */
/*   Updated: 2025/01/15 20:47:33 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
