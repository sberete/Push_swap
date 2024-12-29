#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
    int value;
    struct s_list *next;
    struct s_list *prev;
}t_list;

void swap(t_list *ap);
void swap_a(t_list **a);
void swap_b(t_list **b);
void swap_ss(t_list **a, t_list **b);
void push_a(t_list **a, t_list **b);
void push_b(t_list **a, t_list **b);
void rotate(t_list **ap);
void rotate_a(t_list **a);
void rotate_b(t_list **b);
void rotate_rr(t_list **a, t_list **b);
void reverse_rotate(t_list **ap);
void reverse_rotate_a(t_list **a);
void reverse_rotate_b(t_list **b);
void reverse_rotate_rrr(t_list **a, t_list **b);

#endif