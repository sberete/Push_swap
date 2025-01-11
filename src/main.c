/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxriimu <sxriimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:09:09 by sberete           #+#    #+#             */
/*   Updated: 2025/01/10 18:03:41 by sxriimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**split_result;
	int		i;
	int		nbr;

	stack_a = NULL;
	stack_b = NULL;
	i = (argc == 2) ? 0 : 1;
	if (argc < 2)
		return (error());
	if (argc == 2)
	{
		split_result = ft_split(argv[1], ' ');
		if (!split_result)
			return (error());
		while (split_result[i])
		{
			if (valid_number(split_result[i]) == true)
				return (error());
			nbr = ft_atoi(split_result[i]);
			push_back(&stack_a, nbr);
			free(split_result[i]);
			i++;
		}
		free(split_result);
	}
	else if (argc > 2)
	{
		while (argv[i])
		{
			if (valid_number(argv[i]) == true)
				return (error());
			nbr = ft_atoi(argv[i]);
			push_back(&stack_a, nbr);
			i++;
		}
	}
	if (check_doublon(stack_a) == true)
		return (error());
	print_stack(stack_a);
	if (ft_lstsize(stack_a) == 2)
		sort_two(&stack_a);
	else if (ft_lstsize(stack_a) == 3)	
		sort_three(&stack_a);
	else if (ft_lstsize(stack_a) > 3)
	{
		push_to_b(&stack_a, &stack_b);
		sort_three(&stack_a);
	}
	sort_stack(&stack_a, &stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
}
