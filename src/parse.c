#include "push_swap.h"

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

int	parse(t_node **stack_a, char **argv, int argc)
{
	char	**split_result;
	int		i;
	int		nbr;

	if (argc == 2)
	{
		split_result = ft_split(argv[1], ' ');
		if (!split_result)
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
	}
	return (0);
}

int	parse_arg(t_node **stack_a, char **argv, int argc)
{
	int	i;
	int	nbr;

	if (argc > 2)
	{
		i = 1;
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
