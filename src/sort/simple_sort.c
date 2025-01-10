#include "push_swap.h"

static int find_min_position(t_stack *stack)
{
    t_node *current;
    int min;
    int pos;
    int min_pos;

    if (!stack || !stack->top)
        return (-1);
    current = stack->top;
    min = current->value;
    pos = 0;
    min_pos = 0;
    while (current)
    {
        if (current->value < min)
        {
            min = current->value;
            min_pos = pos;
        }
        pos++;
        current = current->next;
    }
    return (min_pos);
}

void simple_sort(t_stack *a, t_stack *b)
{
    int min_pos;
    int size;

    while (a->size > 0)
    {
        size = a->size;
        min_pos = find_min_position(a);
        
        if (min_pos <= size / 2)
        {
            while (min_pos-- > 0)
                ra(a);
        }
        else
        {
            min_pos = size - min_pos;
            while (min_pos-- > 0)
                rra(a);
        }
        pb(b, a);
    }

    while (b->size > 0)
        pa(a, b);
}
