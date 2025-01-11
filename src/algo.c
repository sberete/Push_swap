/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:18:50 by sberete           #+#    #+#             */
/*   Updated: 2025/01/11 23:26:29 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Créer un algo pour quand j'ai 3 noeuds
	Un autre algo pour quand j'ai plus de 3 noeuds
	Fonction pour push de la stack_a à la stack_b jusqu'à ce qu'il reste 3 noeuds
	Fonction pour trier les 3 noeuds
	Fonction pour le calcul de cout
	Fonction pour le meilleur cout
*/

void	push_to_b(t_node **a, t_node **b)
{
	while (ft_lstsize(*a) > 3)
		push_b(a, b);
}

void	sort_two(t_node **a)
{
	int	first;
	int	second;

	first = (*a)->value;
	second = (*a)->next->value;
	if (first > second)
		swap_a(a);
	else
		return ;
}

void	sort_three(t_node **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && first > third)
		rotate_a(a);
	else if (second > first && second > third)
		reverse_rotate_a(a);
	sort_two(a);
}

/*
	Une fonction pour calculer le cout pour chaque noeud
	Une fonction pour trouver le meilleur coup
	Une fonction pour appliquer le meilleur coup
	Une fonction pour repeter ça jusqu'a la fin
*/

int	cost_to_top(t_node *stack, int value)
{
	t_node	*temp_stack;
	int		index;
	int		stack_len;

	temp_stack = stack;
	index = 0;
	while (temp_stack && temp_stack->value != value)
	{
		index++;
		temp_stack = temp_stack->next;
	}
	stack_len = ft_lstsize(stack);
	if (index > stack_len / 2)
		return (stack_len - index);
	return (index);
}

int	cheapest_num(t_node *stack)
{
	int	cheap;

	cheap = stack->value;
	while (stack)
	{
		if (cheap > stack->value)
			cheap = stack->value;
		stack = stack->next;
	}
	return (cheap);
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
	return (target->value);
}

int	calcul_cost(t_node *a, t_node *b, int b_value)
{
	int	target;
	int	cost;

	// chercher la target
	target = search_target(a, b_value);
	// cost = cost_to_top(taget) + cost_to_top(noeud dans b)
	cost = cost_to_top(a, target) + cost_to_top(b, b_value);
	return (cost);
}

t_node	*find_best_move(t_node *a, t_node *b)
{
	t_node	*best_node;
	t_node	*current;
	int		min_cost;
	int		current_cost;

	best_node = b;
	current = b;
	min_cost = calcul_cost(a, b, b->value);
	while (current)
	{
		current_cost = calcul_cost(a, b, current->value);
		if (current_cost < min_cost)
		{
			min_cost = current_cost;
			best_node = current;
		}
		current = current->next;
	}
	return (best_node);
}

void	best_move_application(t_node **a, t_node **b)
{
	t_node	*best_node;
	int		cost_best_node;

	best_node = find_best_move(*a, *b);
	ft_printf("%d\n", best_node->value);
	cost_best_node = calcul_cost(*a, *b, best_node->value);
	ft_printf("%d\n", cost_best_node);
	while (cost_best_node > 0 && *b != best_node)
	{
		rotate_b(b);
		cost_best_node--;
	}
	if (*b == best_node)
		push_a(a, b);
	while (cost_best_node > 0)
	{
		rotate_a(a);
		cost_best_node--;
	}
}

void	cheap_to_top(t_node **a)
{
	int	cheap;

	cheap = cheapest_num(*a);
	if (cost_to_top(*a, cheap) > ft_lstsize(*a) / 2)
	{
		while ((*a)->value != cheap)
			reverse_rotate_a(a);
	}
	else
		while ((*a)->value != cheap)
			rotate_a(a);
}

void	sort_stack(t_node **a, t_node **b)
{
	while (*b)
		best_move_application(a, b);
	//cheap_to_top(a);
}
