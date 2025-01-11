/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxriimu <sxriimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:08:33 by sberete           #+#    #+#             */
/*   Updated: 2025/01/07 15:27:55 by sxriimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_node *lst)
{
	t_node	*count;
	int		i;

	i = 1;
	if (!lst)
		return (0);
	count = lst->next;
	while (count)
	{
		count = count->next;
		i++;
	}
	return (i);
}
