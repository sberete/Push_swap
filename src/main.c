/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxriimu <sxriimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:07:38 by sberete           #+#    #+#             */
/*   Updated: 2025/01/25 16:58:52 by sxriimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_node *tmp = stack->head;
	while (tmp)
	{
		ft_printf("%d -> ", tmp->value);
		tmp = tmp->next;
	}
	ft_printf("NULL\n");
}


void	free_stack(t_stack *stack)
{
	t_node *tmp;
	t_node	*next;
	
	tmp = stack->head;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
}

int	main(int argc, char **argv)
{
	t_stack stack_a;
	t_stack stack_b;

	ft_memset(&stack_a, 0, sizeof(t_stack));
	ft_memset(&stack_b, 0, sizeof(t_stack));
	if (parsing(&stack_a, argc, argv) == 1)
	{
		free_stack(&stack_a);
		return error();
	}
	if (stack_a.len == 2)
		sort_two(&stack_a);
	else if (stack_a.len == 3)
		sort_three(&stack_a);
	else if (stack_a.len > 3)
		sort_stack(&stack_a, &stack_b);
	free_stack(&stack_a);
}
