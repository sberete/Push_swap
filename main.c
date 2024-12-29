#include "push_swap.h"

t_list *new_node(int value)
{
    t_list *node = malloc(sizeof(t_list));
    if (!node)
        return NULL;
    node->value = value;
    node->next = NULL;
    return node;
}

void push_front(t_list **stack, int value)
{
    t_list *node = new_node(value);
    if (node)
    {
        node->next = *stack;
        *stack = node;
    }
}

void print_stack(t_list *stack)
{
    while (stack)
    {
        printf("%d -> ", stack->value);
        stack = stack->next;
    }
    printf("NULL\n");
}

int main()
{
    t_list *stack_a = NULL;
    t_list *stack_b = NULL;

    for (int i = 5; i >= 1; i--)
        push_front(&stack_a, i);
    for (int i = 10; i >= 6; i--)
        push_front(&stack_b, i);

    printf("Pile initiale a:\n");
    print_stack(stack_a);

    printf("Pile initiale b:\n");
    print_stack(stack_b);

    swap_ss(&stack_a, &stack_b);

    printf("Pile modifié b:\n");
    print_stack(stack_a);

    printf("Pile initiale b:\n");
    print_stack(stack_b);
}

