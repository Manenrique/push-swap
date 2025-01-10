#include "push_swap.h"

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

static void	error_exit(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

static void	process_input(t_stack *stack_a, char **argv, int i)
{
    long num;

    if (!is_valid_number(argv[i]))
        error_exit();
    num = ft_atol(argv[i]);
    if (num > 2147483647 || num < -2147483648)
        error_exit();
    push(stack_a, (int)num);
}

static int check_operations_flag(int argc, char **argv)
{
    int i;

    i = 1;
    while (i < argc)
    {
        if (argv[i][0] == 'o' && argv[i][1] == 'p' && argv[i][2] == 'e' &&
            argv[i][3] == 'r' && argv[i][4] == 'a' && argv[i][5] == 't' &&
            argv[i][6] == 'i' && argv[i][7] == 'o' && argv[i][8] == 'n' &&
            argv[i][9] == 's' && argv[i][10] == '\0')
            return (1);
        i++;
    }
    return (0);
}

int	main(int argc, char **argv)
{
    t_stack	*stack_a;
    t_stack	*stack_b;
    int		i;
    int     show_operations;

    if (argc < 2)
        return (0);
    show_operations = check_operations_flag(argc, argv);
    stack_a = create_stack();
    stack_b = create_stack();
    if (!stack_a || !stack_b)
        error_exit();
    i = argc - 1;
    while (i > 0)
    {
        if (argv[i][0] != 'o' || argv[i][1] != 'p' || argv[i][2] != 'e' ||
            argv[i][3] != 'r' || argv[i][4] != 'a' || argv[i][5] != 't' ||
            argv[i][6] != 'i' || argv[i][7] != 'o' || argv[i][8] != 'n' ||
            argv[i][9] != 's' || argv[i][10] != '\0')
            process_input(stack_a, argv, i);
        i--;
    }
    if (check_duplicates(stack_a))
        error_exit();
    if (!is_sorted(stack_a))
    {
        if (stack_a->size == 2)
            sort_two(stack_a);
        else if (stack_a->size == 3)
            sort_three(stack_a);
        else
            simple_sort(stack_a, stack_b);
    }
    if (show_operations)
        print_operation_count();
    clear_stack(stack_a);
    clear_stack(stack_b);
    return (0);
}
