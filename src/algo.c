/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxriimu <sxriimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:18:50 by sberete           #+#    #+#             */
/*   Updated: 2025/01/11 14:54:25 by sxriimu          ###   ########.fr       */
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

// cas : 2 1 3
// cas : 3 2 1
// cas : 3 1 2
// cas : 1 3 2
// cas : 2 3 1

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
	if (first > second && second < third && first < third)
		swap_a(a);
	else if (first > second && second > third && first > third)
	{
		rotate_a(a);
		swap_a(a);
	}
	else if (first > second && second < third && first > third)
		rotate_a(a);
	else if (first < second && second > third && first < third)
	{
		reverse_rotate_a(a);
		swap_a(a);
	}
	else if (first < second && second > third && first > third)
		reverse_rotate_a(a);
}

/*
	Une fonction pour calculer le cout pour chaque noeud
	Une fonction pour trouver le meilleur coup
	Une fonction pour appliquer le meilleur coup
	Une fonction pour repeter ça jusqu'a la fin
*/

int	calcul_cost(t_node *a, t_node *b, int b_value)
{
	t_node	*temp_a;
	t_node	*temp_b;
	int		cost_a;
	int		cost_b;

	temp_a = a;
	temp_b = b;
	cost_a = 0;
	cost_b = 0;
	if (!a || !b)
		return (0);
	while (temp_a && temp_a->value < b_value)
	{
		cost_a++;
		temp_a = temp_a->next;
	}
	while (temp_b && temp_b->value != b_value)
	{
		cost_b++;
		temp_b = temp_b->next;
	}
	return (cost_a + cost_b);
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
	int stock = cost_best_node;
	while (cost_best_node > 0)
	{
		rotate_a(a);
		cost_best_node--;
	}
	if(*b == best_node)
		push_a(a, b);	
	while (stock > 0)
	{
		rotate_a(a);
		stock--;
	}
}

void	sort_stack(t_node **a, t_node **b)
{
	while (*b)
		best_move_application(a, b);
}
