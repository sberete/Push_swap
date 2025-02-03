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
        printf("%d -> ", tmp->value);
        tmp = tmp->next;
    }
    printf("NULL\n");
}

void print_rev(t_stack *stack)
{
    t_node *tmp;

    tmp = stack->last;
    while (tmp)
    {
        printf("%d -> ", tmp->value);
        tmp = tmp->prev;
    }
    printf("NULL\n");
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
	if (stack_a.len == 2)
		sort_two(&stack_a);
	else if (stack_a.len == 3)
		sort_three(&stack_a);
	else if (stack_a.len > 3)
		sort_stack(&stack_a, &stack_b);
	//print_stack(&stack_a);
	free_stack(&stack_a);
}

// 9 4 1
// 4 9 1
// 9 1 4
// 1 4
// 9