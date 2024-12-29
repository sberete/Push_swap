#include "push_swap.h"



void swap(t_list *ap)
{
    if (!ap || !(ap->next))
        return;
    int tmp;

    tmp = ap->value;
    ap->value = ap->next->value;
    ap->next->value = tmp;
}

void swap_a(t_list **a)
{
    swap(*a);
    ft_putstr("sa\n");
}
    /*sa (swap a) : Intervertit les 2 premiers éléments au sommet de la pile a.
    Ne fait rien s’il n’y en a qu’un ou aucun.*/
void swap_b(t_list **b)
{
    swap(*b);
    ft_putstr("sb\n");
}
    /*sb (swap b) : Intervertit les 2 premiers éléments au sommet de la pile b.
    Ne fait rien s’il n’y en a qu’un ou aucun.*/
void swap_ss(t_list **a, t_list **b)
{
    swap(*a);
    swap(*b);
    ft_putstr("ss\n");
}
    /*ss : sa et sb en même temps.*/
void push_a(t_list **a, t_list **b)
{
    if (!b || !(*b))
        return ;
    t_list *tmp;

    tmp = *b;
    *b = (*b)->next;
    tmp->next = *a;
    *a = tmp;
    ft_putstr("pa\n");
}
    /*pa (push a) : Prend le premier élément au sommet de b et le met sur a.
    Ne fait rien si b est vide.*/
void push_b(t_list **a, t_list **b)
{
    if (!a || !(*a))
        return ;
    t_list *tmp;

    tmp = *a;
    *a = (*a)->next;
    tmp->next = *b;
    *b = tmp;
    ft_putstr("pb\n");
}
    /*pb (push b) : Prend le premier élément au sommet de a et le met sur b.
    Ne fait rien si a est vide.*/
void rotate(t_list **ap)
{
    if (!ap || !(*ap) || !((*ap)->next))
        return ;
    
    t_list *tmp;
    t_list *i;

    tmp = *ap;
    *ap = (*ap)->next;
    tmp->next = NULL;

    i = *ap;
    while (i->next)
        i = i->next;
    i->next = tmp;
}

void rotate_a(t_list **a)
{
    rotate(a);
    ft_putstr("ra\n");
}
    /*ra (rotate a) : Décale d’une position vers le haut tous les élements de la pile a.
    Le premier élément devient le dernier.*/
void rotate_b(t_list **b)
{
    rotate(b);
    ft_putstr("rb\n");
}
    /*rb (rotate b) : Décale d’une position vers le haut tous les élements de la pile b.
    Le premier élément devient le dernier.*/
void rotate_rr(t_list **a, t_list **b)
{
    rotate(a);
    rotate(b);
    ft_putstr("rr\n");
}
    /*rr : ra et rb en même temps.*/
void reverse_rotate(t_list **ap)
{
    if (!ap || !(*ap) || !((*ap)->next))
        return;
    t_list *tmp = *ap;
    t_list *i = NULL;

    while (tmp->next)
    {
        i = tmp;
        tmp = tmp->next;
    }

    i->next = NULL;
    tmp->next = *ap;
    *ap = tmp;
}

void reverse_rotate_a(t_list **a)
{
    reverse_rotate(a);
    ft_putstr("rra\n");
}
    /*rra (reverse rotate a) : Décale d’une position vers le bas tous les élements de
    la pile a. Le dernier élément devient le premier.*/
void reverse_rotate_b(t_list **b)
{
    reverse_rotate(b);
    ft_putstr("rrb\n");
}
    /*rrb (reverse rotate b) : Décale d’une position vers le bas tous les élements de
    la pile b. Le dernier élément devient le premier.*/
void reverse_rotate_rrr(t_list **a, t_list **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    ft_putstr("rrr\n");
}
    /*rrr : rra et rrb en même temps.*/
