#include "../include/push_swap.h"
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static bool is_space(char c)
{
    return (c == ' ' || c == '\t' || c == '\n'
        || c == '\v' || c == '\f' || c == '\r');
}

static void skip_spaces(const char **str)
{
    while (is_space(**str))
        (*str)++;
}

static long parse_number(const char **str)
{
    long result;
    int sign;

    sign = 1;
    result = 0;
    if (**str == '+' || **str == '-')
    {
        if (**str == '-')
            sign = -1;
        (*str)++;
    }
    if (**str < '0' || **str > '9')
        error_exit("Error");
    while (**str >= '0' && **str <= '9')
    {
        result = result * 10 + (**str - '0');
        if ((sign == 1 && result > INT_MAX)
            || (sign == -1 && -result < INT_MIN))
            error_exit("Error");
        (*str)++;
    }
    return (result * sign);
}

static bool duplicate_value(t_node *stack, int value)
{
    while (stack)
    {
        if (stack->value == value)
            return (true);
        stack = stack->next;
    }
    return (false);
}

static void parse_token(t_node **stack, const char **cursor)
{
    long value;

    value = parse_number(cursor);
    if (**cursor != '\0' && !is_space(**cursor))
        error_exit("Error");
    if (duplicate_value(*stack, (int)value))
        error_exit("Error");
    push_bottom(stack, new_node((int)value));
}

static void parse_string(t_node **stack, const char *arg)
{
    const char *cursor;
    bool has_token;

    cursor = arg;
    has_token = false;
    skip_spaces(&cursor);
    while (*cursor)
    {
        parse_token(stack, &cursor);
        has_token = true;
        skip_spaces(&cursor);
    }
    if (!has_token)
        error_exit("Error");
}

static int compare_ints(const void *a, const void *b)
{
    return (*(const int *)a - *(const int *)b);
}

void    assign_indices(t_node *stack)
{
    int     size;
    int     *values;
    int     i;
    t_node  *current;

    size = stack_size(stack);
    values = malloc(sizeof(int) * size);
    if (!values)
        error_exit("Error");
    current = stack;
    i = 0;
    while (current)
    {
        values[i++] = current->value;
        current = current->next;
    }
    qsort(values, size, sizeof(int), compare_ints);
    current = stack;
    while (current)
    {
        i = 0;
        while (i < size && values[i] != current->value)
            i++;
        current->index = i;
        current = current->next;
    }
    free(values);
}

t_node  *parse_arguments(int argc, char **argv)
{
    t_node *stack;
    int     i;

    stack = NULL;
    if (argc < 2)
        return (NULL);
    i = 1;
    while (i < argc)
    {
        if (!argv[i][0])
            error_exit("Error");
        parse_string(&stack, argv[i]);
        i++;
    }
    if (!stack)
        error_exit("Error");
    return (stack);
}
