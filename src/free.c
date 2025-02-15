/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxriimu <sxriimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:42:47 by sberete           #+#    #+#             */
/*   Updated: 2025/02/04 19:03:39 by sxriimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*tmp;
	t_node	*next;

	tmp = stack->head;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	stack->head = NULL;
	stack->last = NULL;
	stack->len = 0;
}
