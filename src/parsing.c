/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:07:38 by sberete           #+#    #+#             */
/*   Updated: 2025/01/29 17:41:17 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*new_node(int nbr)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->value = nbr;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

static bool	push_back(t_stack *stack, int nbr)
{
	t_node	*node;

	node = new_node(nbr);
	if (node == NULL)
		return (false);
	if (stack->head == NULL)
	{
		stack->head = node;
		stack->last = node;
	}
	else
	{
		node->prev = stack->last;
		stack->last->next = node;
		stack->last = node;
	}
	stack->len++;
	return (true);
}

static int	parse_two_arg(t_stack *stack_a, char **argv)
{
	char	**split_result;
	int		i;
	int		nbr;

	split_result = ft_split(argv[1], ' ');
	if (split_result == NULL)
		return (1);
	i = 0;
	while (split_result[i])
	{
		if (valid_number(split_result[i]) == false)
		{
			free_tab(split_result);
			return (1);
		}
		nbr = ft_atoi(split_result[i]);
		push_back(stack_a, nbr);
		i++;
	}
	free_tab(split_result);
	return (0);
}

static int	parse_mult_args(t_stack *stack_a, char **argv)
{
	int	i;
	int	nbr;

	i = 1;
	while (argv[i])
	{
		if (valid_number(argv[i]) == false)
			return (1);
		nbr = ft_atoi(argv[i]);
		push_back(stack_a, nbr);
		i++;
	}
	return (0);
}

int	parsing(t_stack *stack_a, int argc, char **argv)
{
	if (argc < 2)
		return (1);
	else if (argc == 2 && parse_two_arg(stack_a, argv) == 1)
		return (1);
	else if (argc > 2 && parse_mult_args(stack_a, argv) == 1)
		return (1);
	if (check_doublon(stack_a) == true)
		return (1);
	return (0);
}
