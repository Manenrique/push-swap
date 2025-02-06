#include "push_swap.h"

t_stack *create_stack(void)
{
    t_stack *stack;

    stack = (t_stack *)malloc(sizeof(t_stack));
    if (!stack)
        return (NULL);
    stack->top = NULL;
    stack->size = 0;
    return (stack);
}

void    push(t_stack *stack, int value)
{
    t_node  *new_node;

    if (!stack)
        return ;
    new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node)
        return ;
    new_node->value = value;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}

int     pop(t_stack *stack)
{
    t_node  *temp;
    int     value;

    if (!stack || !stack->top)
        return (0);
    temp = stack->top;
    value = temp->value;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
    return (value);
}

void    clear_stack(t_stack *stack)
{
    t_node  *current;
    t_node  *next;

    if (!stack)
        return ;
    current = stack->top;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    stack->top = NULL;
    stack->size = 0;
}
