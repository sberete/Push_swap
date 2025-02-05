/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxriimu <sxriimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:07:38 by sberete           #+#    #+#             */
/*   Updated: 2025/02/05 22:30:28 by sxriimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

bool	valid_number(char *str)
{
	long long	val;
	int			sign;
	int			i;

	i = 0;
	sign = 1;
	val = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			sign *= -1;
		i++;
	}
	if (str[i] == '\0')
		return (false);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		val = val * 10 + (str[i] - '0');
		if ((sign == 1 && val > INT_MAX) || (sign == -1 && (-val) < INT_MIN))
			return (false);
		i++;
	}
	return (true);
}

bool	check_doublon(t_stack *stack)
{
	t_node	*current;
	t_node	*check;

	current = stack->head;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->value == check->value)
				return (true);
			check = check->next;
		}
		current = current->next;
	}
	return (false);
}

bool	stack_is_not_sorted(t_node *ap)
{
	t_node	*current;
	t_node	*check;

	current = ap;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->value > check->value)
				return (true);
			check = check->next;
		}
		current = current->next;
	}
	return (false);
}
