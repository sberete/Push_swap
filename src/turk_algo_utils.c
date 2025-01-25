#include "push_swap.h"

int	cost_to_top(t_node *stack, int value)
{
	t_node	*temp_stack;
	int		index;

	temp_stack = stack;
	index = 0;
	while (temp_stack && temp_stack->value != value)
	{
		index++;
		temp_stack = temp_stack->next;
	}
	return (index);
}

int	search_target(t_node *a, int b_value)
{
	t_node	*current;
	t_node	*target;

	current = a;
	target = NULL;
	while (current)
	{
		if (current->value > b_value && (target == NULL
				|| current->value < target->value))
			target = current;
		current = current->next;
	}
	if (!target)
		return (cheapest_num(a));
	return (target->value);
}

int	search_target_to_b(t_node *b, int b_value)
{
	t_node	*current;
	t_node	*target;

	current = b;
	target = NULL;
	while (current)
	{
		if (current->value < b_value && (target == NULL
				|| current->value > target->value))
			target = current;
		current = current->next;
	}
	if (!target)
		return (highest_num(b));
	return (target->value);
}