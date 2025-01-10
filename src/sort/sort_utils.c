#include "push_swap.h"

void	sort_two(t_stack *stack)
{
    if (stack->top->value > stack->top->next->value)
        sa(stack);
}

void	sort_three_case_one(t_stack *stack_a, int first, int second, int third)
{
    if (first > second && second < third && first < third)
        sa(stack_a);
    else if (first > second && second > third)
    {
        sa(stack_a);
        rra(stack_a);
    }
}

void	sort_three_case_two(t_stack *stack_a, int first, int second, int third)
{
    if (first > second && second < third && first > third)
        ra(stack_a);
    else if (first < second && second > third && first < third)
    {
        sa(stack_a);
        ra(stack_a);
    }
    else if (first < second && second > third && first > third)
        rra(stack_a);
}

void sort_three(t_stack *stack_a)
{
    int first;
    int second;
    int third;

    if (!stack_a || !stack_a->top || !stack_a->top->next || !stack_a->top->next->next)
        return;
    first = stack_a->top->value;
    second = stack_a->top->next->value;
    third = stack_a->top->next->next->value;

    sort_three_case_one(stack_a, first, second, third);
    sort_three_case_two(stack_a, first, second, third);
}
