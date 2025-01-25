/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxriimu <sxriimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:09:00 by sberete           #+#    #+#             */
/*   Updated: 2025/01/25 15:43:43 by sxriimu          ###   ########.fr       */
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
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	size_t len;
	t_node *head;
	t_node *last;
}				t_stack;


typedef struct s_cost
{
	int ra;
	int rra;
	int rb;
	int rrb;$
}				t_cost;


void				swap_a(t_stack *a);
void				swap_b(t_stack *a);
void				swap_ss(t_stack *a, t_stack *b);
void				push_a(t_stack *a, t_stack *b);
void				push_b(t_stack *a, t_stack *b);
void				rotate_a(t_stack *a);
void				rotate_b(t_stack *b);
void				rotate_rr(t_stack *a, t_stack *b);
void				reverse_rotate_a(t_stack *a);
void				reverse_rotate_b(t_stack *b);
void				reverse_rotate_rrr(t_stack *a, t_stack *b);

void				rrr(t_node **a, t_node **b, int *cost_a, int *cost_b);
void				rr(t_node **a, t_node **b, int *cost_a, int *cost_b);
void				rra(t_node **a, int *cost_a);
void				ra(t_node **a, int *cost_a);
void				rrb(t_node **b, int *cost_b);
void				rb(t_node **b, int *cost_b);
int					error(void);

int					ft_lstsize(t_node *stack);
int					cheapest_num(t_node *stack);
int	highest_num(t_node *stack);
int	calcul_cost_to_b(t_node *a, t_node *b, int a_value);
t_node	*find_best_move_to_b(t_node *a, t_node *b);
int	search_target_to_b(t_node *b, int b_value);
bool				valid_number(char *nbr);
bool				check_doublon(t_node *stack);

t_node				*new_node(int nbr);
void				push_back(t_node **stack, int nbr);
int					parsing(t_node **stack, int argc, char **argv);

void				sort_two(t_node **stack);
void				sort_three(t_node **stack);
void				sort_stack(t_node **a, t_node **b);
void				push_to_b(t_node **a, t_node **b);
int					cost_to_top(t_node *stack, int value);
int					search_target(t_node *a, int b_value);

void				print_stack(t_node *stack);
#endif