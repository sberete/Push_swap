/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxriimu <sxriimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:09:09 by sberete           #+#    #+#             */
/*   Updated: 2025/01/15 16:07:44 by sxriimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node *stack)
{
	while (stack)
	{
		printf("%d -> ", stack->value);
		stack = stack->next;
	}
	printf("NULL\n");
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	parsing(&stack_a, argv, argc);
	print_stack(stack_a);
	if (ft_lstsize(stack_a) == 2)
		sort_two(&stack_a);
	else if (ft_lstsize(stack_a) == 3)
		sort_three(&stack_a);
	else if (ft_lstsize(stack_a) > 3)
		sort_stack(&stack_a, &stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
}
