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

int	search_target(t_node *stack_a, int b_value)
{
	t_node	*current;
	t_node	*target;

	current = stack_a;
	target = NULL;
	while (current)
	{
		if (current->value > b_value && (target == NULL
				|| current->value < target->value))
			target = current;
		current = current->next;
	}
	if (!target)
		return (cheapest_num(stack_a));
	return (target->value);
}

int	search_target_to_b(t_node *stack_b, int b_value)
{
	t_node	*current;
	t_node	*target;

	current = stack_b;
	target = NULL;
	while (current)
	{
		if (current->value < b_value && (target == NULL
				|| current->value > target->value))
			target = current;
		current = current->next;
	}
	if (!target)
		return (highest_num(stack_b));
	return (target->value);
}

void	cheap_to_top(t_stack *stack)
{
	int cheap;
	size_t cost;

	cheap = cheapest_num(stack->head);
	cost = cost_to_top(stack->head, cheap);
	if (cost > stack->len / 2)
	{
		while (stack->head->value != cheap)
			reverse_rotate_a(stack);
	}
	while (stack->head->value != cheap)
		rotate_a(stack);
}