#include "push_swap.h"

static void swap_stack(t_stack *stack)
{
    t_node  *first;
    t_node  *second;
    int     temp;

    if (!stack || !stack->top || !stack->top->next)
        return;
    first = stack->top;
    second = first->next;
    temp = first->value;
    first->value = second->value;
    second->value = temp;
}

void    sa(t_stack *stack_a)
{
    swap_stack(stack_a);
    write(1, "sa\n", 3);
    increment_operation_count();
}

void    sb(t_stack *stack_b)
{
    swap_stack(stack_b);
    write(1, "sb\n", 3);
    increment_operation_count();
}

void    ss(t_stack *stack_a, t_stack *stack_b)
{
    swap_stack(stack_a);
    swap_stack(stack_b);
    write(1, "ss\n", 3);
    increment_operation_count();
}
