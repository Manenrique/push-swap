#include "push_swap.h"

void    sa(t_stack *stack_a)
{
    t_node  *first;
    t_node  *second;
    int     temp;

    if (!stack_a || !stack_a->top || !stack_a->top->next)
        return;
    first = stack_a->top;
    second = first->next;
    temp = first->value;
    first->value = second->value;
    second->value = temp;
    write(1, "sa\n", 3);
}

void    sb(t_stack *stack_b)
{
    t_node  *first;
    t_node  *second;
    int     temp;

    if (!stack_b || !stack_b->top || !stack_b->top->next)
        return;
    first = stack_b->top;
    second = first->next;
    temp = first->value;
    first->value = second->value;
    second->value = temp;
    write(1, "sb\n", 3);
}

void    ss(t_stack *stack_a, t_stack *stack_b)
{
    sa(stack_a);
    sb(stack_b);
    write(1, "ss\n", 3);
}
