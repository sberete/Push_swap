/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxriimu <sxriimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:09:00 by sberete           #+#    #+#             */
/*   Updated: 2025/01/26 17:32:40 by sxriimu          ###   ########.fr       */
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
	size_t			len;
	t_node			*head;
	t_node			*last;
}					t_stack;

typedef struct s_cost
{
	size_t				ra;
	size_t				rra;
	size_t				rb;
	size_t				rrb;
	size_t				total;
}					t_cost;

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
int					error(void);

int					cheapest_num(t_node *stack);
int					highest_num(t_node *stack);
int					calcul_cost_to_b(t_node *a, t_node *b, int a_value);
t_node				*find_best_move_to_b(t_node *a, t_node *b);
int					search_target_to_b(t_node *b, int b_value);
bool				valid_number(char *nbr);
bool				check_doublon(t_stack *stack);

t_node				*new_node(int nbr);
bool				push_back(t_stack *stack, int nbr);
int					parsing(t_stack *stack_a, int argc, char **argv);

void				sort_two(t_stack *stack);
void	sort_two_b(t_stack *stack);
void				sort_three(t_stack *stack);

void	sort_three_b(t_stack *stack);
void				sort_stack(t_stack *stack_a, t_stack *stack_b);
void				push_to_b(t_stack *stack_a, t_stack *stack_b);

int					cost_to_top(t_node *stack, int value);
int					search_target(t_node *a, int b_value);
int	search_target_to_b(t_node *stack_b, int b_value);
void				print_stack(t_stack *stack);
#endif