/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:09:09 by sberete           #+#    #+#             */
/*   Updated: 2025/01/05 20:53:05 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

t_node	*new_node(int nbr)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->value = nbr;
	node->next = NULL;
	return (node);
}

void	push_back(t_node **stack, int nbr)
{
	t_node	*node;
	t_node	*current;

	node = new_node(nbr);
	if (node == NULL)
		return ;
	if (*stack == NULL)
	{
		*stack = node;
		return ;
	}
	current = *stack;
	while (current->next)
		current = current->next;
	current->next = node;
}

void	print_stack(t_node *stack)
{
	while (stack)
	{
		printf("%d -> ", stack->value);
		stack = stack->next;
	}
	printf("NULL\n");
}
/*
int	parse_arg(t_node **stack_a, char **argv, int argc)
{
	char	**split_result;
	int		i;
	int		nbr;

	i = (argc == 2) ? 0 : 1;
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
			push_back(stack_a, nbr);
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
			push_back(stack_a, nbr);
			i++;
		}
	}
	return (0);
}
*/
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
	push_to_b(&stack_a, &stack_b);
	sort_three(&stack_a);
	print_stack(stack_a);
}
