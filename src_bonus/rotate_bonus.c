/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:07:38 by sberete           #+#    #+#             */
/*   Updated: 2025/01/15 20:47:26 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
