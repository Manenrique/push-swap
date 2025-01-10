#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
    int             value;
    struct s_node   *next;
}   t_node;

typedef struct s_stack
{
    t_node  *top;
    int     size;
}   t_stack;

// Stack operations
t_stack *create_stack(void);
void    push(t_stack *stack, int value);
int     pop(t_stack *stack);
void    clear_stack(t_stack *stack);

// Swap operations
void    sa(t_stack *stack_a);
void    sb(t_stack *stack_b);
void    ss(t_stack *stack_a, t_stack *stack_b);

// Push operations
void    pa(t_stack *stack_a, t_stack *stack_b);
void    pb(t_stack *stack_b, t_stack *stack_a);

// Rotate operations
void    ra(t_stack *stack_a);
void    rb(t_stack *stack_b);
void    rr(t_stack *stack_a, t_stack *stack_b);

// Reverse rotate operations
void    rra(t_stack *stack_a);
void    rrb(t_stack *stack_b);
void    rrr(t_stack *stack_a, t_stack *stack_b);

// Sort operations
void    sort_two(t_stack *stack);
void    sort_three(t_stack *stack_a);
void    simple_sort(t_stack *a, t_stack *b);

// Quicksort
void    quicksort_a(t_stack *a, t_stack *b, int size);

// Utils
long    ft_atol(const char *str);
int     is_sorted(t_stack *stack);
void    increment_operation_count(void);
void    print_operation_count(void);

#endif
