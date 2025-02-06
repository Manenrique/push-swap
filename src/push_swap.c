#include "push_swap.h"

void	error_exit(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

void	cleanup_and_exit(t_stack *stack_a, t_stack *stack_b, int error)
{
    if (stack_a)
    {
        clear_stack(stack_a);
        free(stack_a);
    }
    if (stack_b)
    {
        clear_stack(stack_b);
        free(stack_b);
    }
    if (error)
        error_exit();
    exit(0);
}

static int	is_valid_number(char *str)
{
    int	i;

    i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    if (!str[i])
        return (0);
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

static int	check_duplicates(t_stack *stack)
{
    t_node	*current;
    t_node	*check;

    current = stack->top;
    while (current)
    {
        check = current->next;
        while (check)
        {
            if (current->value == check->value)
                return (1);
            check = check->next;
        }
        current = current->next;
    }
    return (0);
}

static void	process_input(t_stack *stack_a, char **argv, int i)
{
    long num;

    num = ft_atol(argv[i]);
    if (num > 2147483647 || num < -2147483648)
        cleanup_and_exit(stack_a, NULL, 1);
    push(stack_a, (int)num);
}

static void	process_string_input(t_stack *stack_a, char *str)
{
    char	**numbers;
    int		i;

    numbers = ft_split(str, ' ');
    if (!numbers)
        cleanup_and_exit(stack_a, NULL, 1);
    i = 0;
    while (numbers[i])
    {
        if (!is_valid_number(numbers[i]))
        {
            free_split(numbers);
            cleanup_and_exit(stack_a, NULL, 1);
        }
        process_input(stack_a, numbers, i);
        i++;
    }
    free_split(numbers);
}

int	main(int argc, char **argv)
{
    t_stack	*stack_a;
    t_stack	*stack_b;
    int		i;

    stack_a = NULL;
    stack_b = NULL;
    if (argc < 2)
        cleanup_and_exit(NULL, NULL, 0);
    stack_a = create_stack();
    stack_b = create_stack();
    if (!stack_a || !stack_b)
        cleanup_and_exit(stack_a, stack_b, 1);
    
    if (argc == 2)
        process_string_input(stack_a, argv[1]);
    else
    {
        i = 1;
        while (i < argc)
        {
            if (!is_valid_number(argv[i]))
                cleanup_and_exit(stack_a, stack_b, 1);
            process_input(stack_a, argv, i);
            i++;
        }
    }
    
    if (check_duplicates(stack_a))
        cleanup_and_exit(stack_a, stack_b, 1);
    
    if (!is_sorted(stack_a))
        simple_sort(stack_a, stack_b);
    
    cleanup_and_exit(stack_a, stack_b, 0);
    return (0);
}
