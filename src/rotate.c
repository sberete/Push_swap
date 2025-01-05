/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 22:25:28 by sberete           #+#    #+#             */
/*   Updated: 2025/01/05 20:52:38 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node **ap)
{
	t_node	*tmp;
	t_node	*i;

	if (!ap || !(*ap) || !((*ap)->next))
		return ;
	tmp = *ap;
	*ap = (*ap)->next;
	tmp->next = NULL;
	i = *ap;
	while (i->next)
		i = i->next;
	i->next = tmp;
}

void	rotate_a(t_node **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rotate_b(t_node **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rotate_rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
