#include "push_swap.h"

static void reverse_rotate_stack(t_stack *stack)
{
    t_node  *last;
    t_node  *second_last;

    if (!stack || !stack->top || !stack->top->next)
        return;
    last = stack->top;
    second_last = NULL;
    while (last->next)
    {
        second_last = last;
        last = last->next;
    }
    second_last->next = NULL;
    last->next = stack->top;
    stack->top = last;
}

void    rra(t_stack *stack_a)
{
    reverse_rotate_stack(stack_a);
    write(1, "rra\n", 4);
}

void    rrb(t_stack *stack_b)
{
    reverse_rotate_stack(stack_b);
    write(1, "rrb\n", 4);
}

void    rrr(t_stack *stack_a, t_stack *stack_b)
{
    reverse_rotate_stack(stack_a);
    reverse_rotate_stack(stack_b);
    write(1, "rrr\n", 4);
}
