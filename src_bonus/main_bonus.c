/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:07:38 by sberete           #+#    #+#             */
/*   Updated: 2025/01/15 22:04:21 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	print_stack(t_node *stack)
{
	while (stack)
	{
		printf(""%d -> ", stack->value);
		stack = stack->next;
	}
	printf(""NULL\n");
}

void	free_stack(t_node *a)
{
	while (a)
	{
		free(a);
		a = a->next;
	}
	free(a);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	parsing(&stack_a, argc, argv);
	print_stack(stack_a);
	if (ft_lstsize(stack_a) == 2)
		sort_two(&stack_a);
	else if (ft_lstsize(stack_a) == 3)
		sort_three(&stack_a);
	else if (ft_lstsize(stack_a) > 3)
		sort_stack(&stack_a, &stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
	free_stack(stack_a);
	if (stack_is_not_sorted(stack_a) == true)
		return (ko());
	else
		return (ok());
}
