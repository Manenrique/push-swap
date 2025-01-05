#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

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

// Push_swap operations
void    sa(t_stack *stack_a);
void    sb(t_stack *stack_b);
void    ss(t_stack *stack_a, t_stack *stack_b);
void    pa(t_stack *stack_a, t_stack *stack_b);
void    pb(t_stack *stack_b, t_stack *stack_a);
void    ra(t_stack *stack_a);
void    rb(t_stack *stack_b);
void    rr(t_stack *stack_a, t_stack *stack_b);
void    rra(t_stack *stack_a);
void    rrb(t_stack *stack_b);
void    rrr(t_stack *stack_a, t_stack *stack_b);

// Utils
int     is_sorted(t_stack *stack);
void    error_exit(void);

#endif
