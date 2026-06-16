#include "../include/push_swap.h"
#include <string.h>
#include <unistd.h>

static void print_op(const char *operation)
{
    write(1, operation, strlen(operation));
}

void    swap(t_node **stack)
{
    t_node *first;
    t_node *second;

    if (!stack || !*stack || !(*stack)->next)
        return ;
    first = *stack;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack = second;
}

void    rotate(t_node **stack)
{
    t_node *first;
    t_node *last;

    if (!stack || !*stack || !(*stack)->next)
        return ;
    first = pop_front(stack);
    last = *stack;
    while (last->next)
        last = last->next;
    last->next = first;
}

void    reverse_rotate(t_node **stack)
{
    t_node *before_last;
    t_node *last;

    if (!stack || !*stack || !(*stack)->next)
        return ;
    before_last = *stack;
    while (before_last->next->next)
        before_last = before_last->next;
    last = before_last->next;
    before_last->next = NULL;
    last->next = *stack;
    *stack = last;
}

void    sa(t_node **a)
{
    swap(a);
    print_op("sa\n");
}

void    sb(t_node **b)
{
    swap(b);
    print_op("sb\n");
}

void    ss(t_node **a, t_node **b)
{
    swap(a);
    swap(b);
    print_op("ss\n");
}

void    pa(t_node **a, t_node **b)
{
    t_node *node;

    node = pop_front(b);
    if (!node)
        return ;
    push_front(a, node);
    print_op("pa\n");
}

void    pb(t_node **a, t_node **b)
{
    t_node *node;

    node = pop_front(a);
    if (!node)
        return ;
    push_front(b, node);
    print_op("pb\n");
}

void    ra(t_node **a)
{
    rotate(a);
    print_op("ra\n");
}

void    rb(t_node **b)
{
    rotate(b);
    print_op("rb\n");
}

void    rr(t_node **a, t_node **b)
{
    rotate(a);
    rotate(b);
    print_op("rr\n");
}

void    rra(t_node **a)
{
    reverse_rotate(a);
    print_op("rra\n");
}

void    rrb(t_node **b)
{
    reverse_rotate(b);
    print_op("rrb\n");
}

void    rrr(t_node **a, t_node **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    print_op("rrr\n");
}
