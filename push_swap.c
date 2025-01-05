#include "push_swap.h"

static int	ft_atoi(const char *str)
{
    int	i;
    int	sign;
    int	result;

    i = 0;
    sign = 1;
    result = 0;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (result * sign);
}

static int is_sorted(t_stack *stack)
{
    t_node *current;

    if (!stack || !stack->top)
        return (1);
    current = stack->top;
    while (current->next)
    {
        if (current->value > current->next->value)
            return (0);
        current = current->next;
    }
    return (1);
}

static void sort_three(t_stack *stack_a)
{
    int first;
    int second;
    int third;

    if (!stack_a || !stack_a->top || !stack_a->top->next || !stack_a->top->next->next)
        return;
    first = stack_a->top->value;
    second = stack_a->top->next->value;
    third = stack_a->top->next->next->value;

    if (first > second && second < third && first < third)
        sa(stack_a);
    else if (first > second && second > third)
    {
        sa(stack_a);
        rra(stack_a);
    }
    else if (first > second && second < third && first > third)
        ra(stack_a);
    else if (first < second && second > third && first < third)
    {
        sa(stack_a);
        ra(stack_a);
    }
    else if (first < second && second > third && first > third)
        rra(stack_a);
}

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int     i;

    if (argc < 2)
        return (0);
    
    // Crear las pilas
    stack_a = create_stack();
    stack_b = create_stack();
    if (!stack_a || !stack_b)
    {
        write(2, "Error\n", 6);
        return (1);
    }

    // Cargar números en la pila a (en orden inverso para mantener el orden de entrada)
    for (i = argc - 1; i > 0; i--)
    {
        push(stack_a, ft_atoi(argv[i]));
    }

    // Si ya está ordenado, no hacer nada
    if (!is_sorted(stack_a))
    {
        // Por ahora solo manejamos el caso de 3 números
        if (stack_a->size == 2)
        {
            if (stack_a->top->value > stack_a->top->next->value)
                sa(stack_a);
        }
        else if (stack_a->size == 3)
            sort_three(stack_a);
    }

    // Limpieza
    clear_stack(stack_a);
    clear_stack(stack_b);
    return (0);
}
