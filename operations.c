#include "push_swap.h"

void    sa(t_stack *stack_a)
{
    t_node  *first;
    t_node  *second;
    int     temp;

    if (!stack_a || !stack_a->top || !stack_a->top->next)
        return ;
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
        return ;
    first = stack_b->top;
    second = first->next;
    temp = first->value;
    first->value = second->value;
    second->value = temp;
    write(1, "sb\n", 3);
}

void    ss(t_stack *stack_a, t_stack *stack_b)
{
    t_node  *first;
    t_node  *second;
    int     temp;

    if (stack_a && stack_a->top && stack_a->top->next)
    {
        first = stack_a->top;
        second = first->next;
        temp = first->value;
        first->value = second->value;
        second->value = temp;
    }
    if (stack_b && stack_b->top && stack_b->top->next)
    {
        first = stack_b->top;
        second = first->next;
        temp = first->value;
        first->value = second->value;
        second->value = temp;
    }
    write(1, "ss\n", 3);
}

void    pa(t_stack *stack_a, t_stack *stack_b)
{
    int value;

    if (!stack_b || !stack_b->top)
        return ;
    value = pop(stack_b);
    push(stack_a, value);
    write(1, "pa\n", 3);
}

void    pb(t_stack *stack_b, t_stack *stack_a)
{
    int value;

    if (!stack_a || !stack_a->top)
        return ;
    value = pop(stack_a);
    push(stack_b, value);
    write(1, "pb\n", 3);
}

void    ra(t_stack *stack_a)
{
    t_node  *first;
    t_node  *last;

    if (!stack_a || !stack_a->top || !stack_a->top->next)
        return ;
    last = stack_a->top;
    while (last->next)
        last = last->next;
    first = stack_a->top;
    stack_a->top = first->next;
    first->next = NULL;
    last->next = first;
    write(1, "ra\n", 3);
}

void    rb(t_stack *stack_b)
{
    t_node  *first;
    t_node  *last;

    if (!stack_b || !stack_b->top || !stack_b->top->next)
        return ;
    last = stack_b->top;
    while (last->next)
        last = last->next;
    first = stack_b->top;
    stack_b->top = first->next;
    first->next = NULL;
    last->next = first;
    write(1, "rb\n", 3);
}

void    rr(t_stack *stack_a, t_stack *stack_b)
{
    t_node  *first;
    t_node  *last;

    if (stack_a && stack_a->top && stack_a->top->next)
    {
        last = stack_a->top;
        while (last->next)
            last = last->next;
        first = stack_a->top;
        stack_a->top = first->next;
        first->next = NULL;
        last->next = first;
    }
    if (stack_b && stack_b->top && stack_b->top->next)
    {
        last = stack_b->top;
        while (last->next)
            last = last->next;
        first = stack_b->top;
        stack_b->top = first->next;
        first->next = NULL;
        last->next = first;
    }
    write(1, "rr\n", 3);
}

void    rra(t_stack *stack_a)
{
    t_node  *last;
    t_node  *second_last;

    if (!stack_a || !stack_a->top || !stack_a->top->next)
        return ;
    last = stack_a->top;
    second_last = NULL;
    while (last->next)
    {
        second_last = last;
        last = last->next;
    }
    second_last->next = NULL;
    last->next = stack_a->top;
    stack_a->top = last;
    write(1, "rra\n", 4);
}

void    rrb(t_stack *stack_b)
{
    t_node  *last;
    t_node  *second_last;

    if (!stack_b || !stack_b->top || !stack_b->top->next)
        return ;
    last = stack_b->top;
    second_last = NULL;
    while (last->next)
    {
        second_last = last;
        last = last->next;
    }
    second_last->next = NULL;
    last->next = stack_b->top;
    stack_b->top = last;
    write(1, "rrb\n", 4);
}

void    rrr(t_stack *stack_a, t_stack *stack_b)
{
    t_node  *last;
    t_node  *second_last;

    if (stack_a && stack_a->top && stack_a->top->next)
    {
        last = stack_a->top;
        second_last = NULL;
        while (last->next)
        {
            second_last = last;
            last = last->next;
        }
        second_last->next = NULL;
        last->next = stack_a->top;
        stack_a->top = last;
    }
    if (stack_b && stack_b->top && stack_b->top->next)
    {
        last = stack_b->top;
        second_last = NULL;
        while (last->next)
        {
            second_last = last;
            last = last->next;
        }
        second_last->next = NULL;
        last->next = stack_b->top;
        stack_b->top = last;
    }
    write(1, "rrr\n", 4);
}
