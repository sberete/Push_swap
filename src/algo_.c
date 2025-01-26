/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxriimu <sxriimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:26:24 by sberete           #+#    #+#             */
/*   Updated: 2025/01/26 17:48:35 by sxriimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->len > 3)
		push_b(stack_a, stack_b);
}

void	sort_two(t_stack *stack)
{
	int	first;
	int	second;

	first = stack->head->value;
	second = stack->head->next->value;
	if (first > second)
		swap_a(stack);
	else
		return ;
}

void	sort_two_b(t_stack *stack)
{
	int	first;
	int	second;

	first = stack->head->value;
	second = stack->head->next->value;
	if (first < second)
		swap_a(stack);
	else
		return ;
}

void	sort_three(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	first = stack->head->value;
	second = stack->head->next->value;
	third = stack->head->next->next->value;
	if (first > second && first > third)
		rotate_a(stack);
	else if (second > first && second > third)
		reverse_rotate_a(stack);
	sort_two(stack);
}

void	sort_three_b(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	first = stack->head->value;
	second = stack->head->next->value;
	third = stack->head->next->next->value;
	if (third > first && third > second)
		reverse_rotate_b(stack);
	else if (second > first && second > third)
		rotate_b(stack);
	sort_two_b(stack);
}

