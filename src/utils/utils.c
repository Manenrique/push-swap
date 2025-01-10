#include "push_swap.h"

static long	process_digits(const char *str, int *i, int sign)
{
    long	result;

    result = 0;
    while (str[*i] >= '0' && str[*i] <= '9')
    {
        result = result * 10 + (str[*i] - '0');
        if ((sign == 1 && result > 2147483647) || 
            (sign == -1 && result > 2147483648))
            return (2147483648);
        (*i)++;
    }
    return (result);
}

long	ft_atol(const char *str)
{
    int		i;
    int		sign;
    long	result;

    i = 0;
    sign = 1;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    result = process_digits(str, &i, sign);
    return (result * sign);
}

int is_sorted(t_stack *stack)
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
