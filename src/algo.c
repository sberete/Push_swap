/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:18:50 by sberete           #+#    #+#             */
/*   Updated: 2025/01/05 20:54:42 by dtoure           ###   ########.fr       */
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

/*int cost(t_node **a, t_node **b)
{
	int cost;
}*/
