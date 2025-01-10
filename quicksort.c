#include "push_swap.h"

static int find_pivot(t_stack *stack, int size)
{
    t_node *current;
    int min;
    int max;
    
    if (!stack || !stack->top)
        return (0);
    current = stack->top;
    min = current->value;
    max = current->value;
    while (size-- > 0 && current)
    {
        if (current->value < min)
            min = current->value;
        if (current->value > max)
            max = current->value;
        current = current->next;
    }
    return ((min + max) / 2);
}

static int partition_stack(t_stack *a, t_stack *b, int size, int pivot)
{
    int pushed;
    int i;
    
    pushed = 0;
    i = 0;
    while (i < size)
    {
        if (a->top->value < pivot)
        {
            pb(b, a);
            pushed++;
        }
        else
            ra(a);
        i++;
    }
    return (pushed);
}

void quicksort_a(t_stack *a, t_stack *b, int size)
{
    int pivot;
    int pushed;
    int rotated;
    
    if (size <= 3)
    {
        if (size == 2)
            sort_two(a);
        else if (size == 3)
            sort_three(a);
        return;
    }
    
    pivot = find_pivot(a, size);
    pushed = partition_stack(a, b, size, pivot);
    rotated = size - pushed;
    
    quicksort_a(a, b, rotated);
    
    while (pushed--)
    {
        pa(a, b);
        ra(a);
    }
}
