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
}

void    sb(t_stack *stack_b)
{
    swap_stack(stack_b);
    write(1, "sb\n", 3);
}

void    ss(t_stack *stack_a, t_stack *stack_b)
{
    swap_stack(stack_a);
    swap_stack(stack_b);
    write(1, "ss\n", 3);
}

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
