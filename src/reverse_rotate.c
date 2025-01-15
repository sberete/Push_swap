/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:07:38 by sberete           #+#    #+#             */
/*   Updated: 2025/01/15 19:59:09 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_node **ap)
{
	t_node	*tmp;
	t_node	*i;

	if (!ap || !(*ap) || !((*ap)->next))
		return ;
	tmp = *ap;
	i = NULL;
	while (tmp->next)
	{
		i = tmp;
		tmp = tmp->next;
	}
	i->next = NULL;
	tmp->next = *ap;
	*ap = tmp;
}

void	reverse_rotate_a(t_node **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_node **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	reverse_rotate_rrr(t_node **a, t_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
