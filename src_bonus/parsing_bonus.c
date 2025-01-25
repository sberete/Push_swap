/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxriimu <sxriimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:07:38 by sberete           #+#    #+#             */
/*   Updated: 2025/01/16 00:07:43 by sxriimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

int	parse_two_arg(t_node **stack_a, char **argv)
{
	char	**split_result;
	int		i;
	int		nbr;

	split_result = ft_split(argv[1], ' ');
	if (split_result == NULL)
		return (error());
	i = 0;
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
	return (0);
}

int	parse_mult_args(t_node **stack_a, char **argv)
{
	int	i;
	int	nbr;

	i = 1;
	while (argv[i])
	{
		if (valid_number(argv[i]) == true)
			return (error());
		nbr = ft_atoi(argv[i]);
		push_back(stack_a, nbr);
		i++;
	}
	return (0);
}

int	parsing(t_node **stack_a, int argc, char **argv)
{
	if (argc < 2)
		return (1);
	else if (argc == 2)
		parse_two_arg(stack_a, argv);
	else if (argc > 2)
		parse_mult_args(stack_a, argv);
	if (check_doublon(*stack_a) == true)
		return (1);
	return (0);
}
