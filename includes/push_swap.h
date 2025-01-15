/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxriimu <sxriimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:09:00 by sberete           #+#    #+#             */
/*   Updated: 2025/01/14 20:48:02 by sxriimu          ###   ########.fr       */
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

void				swap_a(t_node **);
void				swap_b(t_node **);
void				swap_ss(t_node **, t_node **);
void				push_a(t_node **, t_node **);
void				push_b(t_node **, t_node **);
void				rotate_a(t_node **);
void				rotate_b(t_node **);
void				rotate_rr(t_node **, t_node **);
void				reverse_rotate_a(t_node **);
void				reverse_rotate_b(t_node **);
void				reverse_rotate_rrr(t_node **, t_node **);

int					error(void);
int					ft_lstsize(t_node *);
bool				valid_number(char *);
bool				check_doublon(t_node *);

t_node				*new_node(int);
void				push_back(t_node **, int);
int					parsing(t_node **, char **, int);

void				sort_two(t_node **);
void				sort_three(t_node **);
void				sort_stack(t_node **, t_node **);

void				print_stack(t_node *stack);
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
