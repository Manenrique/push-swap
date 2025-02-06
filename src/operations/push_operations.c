#include "push_swap.h"

void    pa(t_stack *stack_a, t_stack *stack_b)
{
    int value;

    if (!stack_b || !stack_b->top)
        return;
    value = pop(stack_b);
    push(stack_a, value);
    write(1, "pa\n", 3);
}

void    pb(t_stack *stack_b, t_stack *stack_a)
{
    int value;

    if (!stack_a || !stack_a->top)
        return;
    value = pop(stack_a);
    push(stack_b, value);
    write(1, "pb\n", 3);
}
