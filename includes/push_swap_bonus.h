/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberete <sberete@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:20:54 by sberete           #+#    #+#             */
/*   Updated: 2025/01/15 22:03:08 by sberete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "ft_printf.h"
# include "libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

void				swap_a(t_node **a);
void				swap_b(t_node **a);
void				swap_ss(t_node **a, t_node **b);
void				push_a(t_node **a, t_node **b);
void				push_b(t_node **a, t_node **b);
void				rotate_a(t_node **a);
void				rotate_b(t_node **b);
void				rotate_rr(t_node **a, t_node **b);
void				reverse_rotate_a(t_node **a);
void				reverse_rotate_b(t_node **b);
void				reverse_rotate_rrr(t_node **a, t_node **b);

int					error(void);
int					ok(void);
int					ko(void);

int					ft_lstsize(t_node *stack);
int					cheapest_num(t_node *stack);

bool				valid_number(char *nbr);
bool				check_doublon(t_node *stack);
bool				stack_is_not_sorted(t_node *ap);

t_node				*new_node(int nbr);
void				push_back(t_node **stack, int nbr);
int					parsing(t_node **stack, int argc, char **argv);

void				sort_two(t_node **stack);
void				sort_three(t_node **stack);
void				sort_stack(t_node **a, t_node **b);

void				print_stack(t_node *stack);
#endif