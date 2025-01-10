#include "push_swap.h"

static int g_operation_count = 0;

void increment_operation_count(void)
{
    g_operation_count++;
}

void print_operation_count(void)
{
    char count_str[20];
    int i = 0;
    int temp = g_operation_count;
    
    if (temp == 0)
    {
        write(1, "Total operations: 0\n", 19);
        return;
    }
    
    // Convert number to string
    while (temp > 0)
    {
        count_str[i++] = (temp % 10) + '0';
        temp /= 10;
    }
    
    write(1, "Total operations: ", 17);
    while (i > 0)
        write(1, &count_str[--i], 1);
    write(1, "\n", 1);
}
