/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxriimu <sxriimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:07:38 by sberete           #+#    #+#             */
/*   Updated: 2025/02/03 15:16:59 by sxriimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_stack *stack)
{
    t_node *tmp;

    tmp = stack->head;
    while (tmp)
    {
        ft_printf("%d -> ", tmp->value);
        tmp = tmp->next;
    }
    ft_printf("NULL\n");
}

void print_rev(t_stack *stack)
{
    t_node *tmp;

    tmp = stack->last;
    while (tmp)
    {
        ft_printf("%d -> ", tmp->value);
        tmp = tmp->prev;
    }
    ft_printf("NULL\n");
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	ft_memset(&stack_a, 0, sizeof(t_stack));
	ft_memset(&stack_b, 0, sizeof(t_stack));
	if (parsing(&stack_a, argc, argv) == 1)
	{
		free_stack(&stack_a);
		return (error());
	}
	push_a(&stack_a, &stack_b);
	push_a(&stack_a, &stack_b);
	push_a(&stack_a, &stack_b);
	push_a(&stack_a, &stack_b);

	print_stack(&stack_a);
	print_rev(&stack_a);
// 	if (stack_a.len == 2)
// 		sort_two(&stack_a);
// 	else if (stack_a.len == 3)
// 		sort_three(&stack_a);
// 	else if (stack_a.len > 3)
// 		sort_stack(&stack_a, &stack_b);
// //	print_stack(&stack_a);
// //	print_stack(&stack_b);
	free_stack(&stack_a);
}
