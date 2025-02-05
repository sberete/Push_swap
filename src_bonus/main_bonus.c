/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxriimu <sxriimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:07:38 by sberete           #+#    #+#             */
/*   Updated: 2025/02/05 23:01:24 by sxriimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	if (stack_is_not_sorted(&stack_a) == true)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free_stack(&stack_a);
}
