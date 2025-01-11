/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxriimu <sxriimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:09:00 by sberete           #+#    #+#             */
/*   Updated: 2025/01/07 22:53:39 by sxriimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
void				swap_b(t_node **b);
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
int					ft_lstsize(t_node *lst);
bool				valid_number(char *str);
bool				check_doublon(t_node *ap);

t_node				*new_node(int nbr);
void				push_back(t_node **stack, int nbr);
void				print_stack(t_node *stack);

void				push_to_b(t_node **a, t_node **b);
void				sort_two(t_node **a);
void				sort_three(t_node **a);
int					calcul_cost(t_node *a, t_node *b, int b_value);
t_node				*find_best_move(t_node *a, t_node *b);
void				best_move_application(t_node **a, t_node **b);
void				sort_stack(t_node **a, t_node **b);
#endif

/*
typedef struct s_stack
{
	t_list			*node;
	size_t			len;
}					t_stack;

typedef struct s_push_swap
{

}					t_push_swap;
*/
