#include "../include/push_swap.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void    error_exit(const char *message)
{
    (void)message;
    write(2, "Error\n", 6);
    exit(EXIT_FAILURE);
}

t_node  *new_node(int value)
{
    t_node *node;

    node = malloc(sizeof(t_node));
    if (!node)
        error_exit("Memory allocation failed");
    node->value = value;
    node->index = -1;
    node->next = NULL;
    return (node);
}

void    free_stack(t_node *stack)
{
    t_node *next;

    while (stack)
    {
        next = stack->next;
        free(stack);
        stack = next;
    }
}

int     stack_size(t_node *stack)
{
    int count;

    count = 0;
    while (stack)
    {
        count++;
        stack = stack->next;
    }
    return (count);
}

bool    stack_sorted(t_node *stack)
{
    while (stack && stack->next)
    {
        if (stack->value > stack->next->value)
            return (false);
        stack = stack->next;
    }
    return (true);
}

void    push_front(t_node **stack, t_node *node)
{
    if (!node)
        return ;
    node->next = *stack;
    *stack = node;
}

void    push_bottom(t_node **stack, t_node *node)
{
    t_node *last;

    if (!node)
        return ;
    node->next = NULL;
    if (!*stack)
    {
        *stack = node;
        return ;
    }
    last = *stack;
    while (last->next)
        last = last->next;
    last->next = node;
}

t_node  *pop_front(t_node **stack)
{
    t_node *head;

    if (!stack || !*stack)
        return (NULL);
    head = *stack;
    *stack = head->next;
    head->next = NULL;
    return (head);
}

static t_node *get_last_node(t_node *stack)
{
    if (!stack)
        return (NULL);
    while (stack->next)
        stack = stack->next;
    return (stack);
}

static t_node *get_before_last(t_node *stack)
{
    if (!stack || !stack->next)
        return (NULL);
    while (stack->next->next)
        stack = stack->next;
    return (stack);
}

t_node  *stack_last(t_node *stack)
{
    return (get_last_node(stack));
}

t_node  *stack_before_last(t_node *stack)
{
    return (get_before_last(stack));
}

void    print_stack(const char *name, t_node *stack)
{
    (void)name;
    while (stack)
    {
        char buffer[32];
        int len;

        len = sprintf(buffer, "%d\n", stack->value);
        write(1, buffer, len);
        stack = stack->next;
    }
}
