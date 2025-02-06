#include "push_swap.h"

static void rotate_stack(t_stack *stack)
{
    t_node  *first;
    t_node  *last;

    if (!stack || !stack->top || !stack->top->next)
        return;
    last = stack->top;
    while (last->next)
        last = last->next;
    first = stack->top;
    stack->top = first->next;
    first->next = NULL;
    last->next = first;
}

void    ra(t_stack *stack_a)
{
    rotate_stack(stack_a);
    write(1, "ra\n", 3);
}

void    rb(t_stack *stack_b)
{
    rotate_stack(stack_b);
    write(1, "rb\n", 3);
}

void    rr(t_stack *stack_a, t_stack *stack_b)
{
    rotate_stack(stack_a);
    rotate_stack(stack_b);
    write(1, "rr\n", 3);
}
