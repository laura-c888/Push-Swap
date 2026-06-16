#include "../include/push_swap.h"

static int  find_min_position(t_node *stack)
{
    int position;
    int min_index;
    int i;

    position = 0;
    i = 0;
    min_index = stack->index;
    while (stack)
    {
        if (stack->index < min_index)
        {
            min_index = stack->index;
            position = i;
        }
        stack = stack->next;
        i++;
    }
    return (position);
}

static void rotate_to_top(t_node **stack, int position)
{
    int size;

    size = stack_size(*stack);
    if (position <= size / 2)
    {
        while (position-- > 0)
            ra(stack);
    }
    else
    {
        position = size - position;
        while (position-- > 0)
            rra(stack);
    }
}

static void sort_three(t_stacks *stacks)
{
    int first;
    int second;
    int third;

    first = stacks->a->index;
    second = stacks->a->next->index;
    third = stacks->a->next->next->index;
    if (first < second && second < third)
        return ;
    if (first > second && second < third && first < third)
        sa(&stacks->a);
    else if (first > second && second > third)
    {
        sa(&stacks->a);
        rra(&stacks->a);
    }
    else if (first > second && second < third && first > third)
        ra(&stacks->a);
    else if (first < second && second > third && first < third)
    {
        sa(&stacks->a);
        ra(&stacks->a);
    }
    else if (first < second && second > third && first > third)
        rra(&stacks->a);
}

static void sort_five(t_stacks *stacks)
{
    while (stack_size(stacks->a) > 3)
    {
        int position;

        position = find_min_position(stacks->a);
        rotate_to_top(&stacks->a, position);
        pb(&stacks->a, &stacks->b);
    }
    sort_three(stacks);
    while (stacks->b)
        pa(&stacks->a, &stacks->b);
}

void    sort_small(t_stacks *stacks)
{
    int size;

    size = stack_size(stacks->a);
    if (size <= 1 || stack_sorted(stacks->a))
        return ;
    if (size == 2)
    {
        if (stacks->a->value > stacks->a->next->value)
            sa(&stacks->a);
        return ;
    }
    if (size == 3)
        sort_three(stacks);
    else
        sort_five(stacks);
}

static int  find_max_position(t_node *stack)
{
    int position;
    int max_index;
    int i;

    position = 0;
    i = 0;
    max_index = stack->index;
    while (stack)
    {
        if (stack->index > max_index)
        {
            max_index = stack->index;
            position = i;
        }
        stack = stack->next;
        i++;
    }
    return (position);
}

static void rotate_to_closest_in_chunk(t_node **a, int limit)
{
    t_node *curr;
    int pos_from_top;
    int pos_from_bottom;
    int size;
    int i;

    pos_from_top = -1;
    pos_from_bottom = -1;
    curr = *a;
    i = 0;
    while (curr)
    {
        if (curr->index < limit)
        {
            if (pos_from_top == -1)
                pos_from_top = i;
            pos_from_bottom = i;
        }
        curr = curr->next;
        i++;
    }
    size = stack_size(*a);
    if (pos_from_top <= size - pos_from_bottom)
    {
        while (pos_from_top-- > 0)
            ra(a);
    }
    else
    {
        int dist = size - pos_from_bottom;
        while (dist-- > 0)
            rra(a);
    }
}

void    sort_medium(t_stacks *stacks)
{
    int size;
    int chunk_size;
    int min_idx;
    int limit;
    int max_pos;
    int b_size;
    int dist;

    size = stack_size(stacks->a);
    if (size <= 5)
    {
        sort_small(stacks);
        return ;
    }
    if (size <= 100)
        chunk_size = 15;
    else
        chunk_size = 31;
    min_idx = 0;
    while (stacks->a)
    {
        limit = min_idx + chunk_size;
        if (stacks->a->index < limit)
        {
            pb(&stacks->a, &stacks->b);
            if (stacks->b->index < min_idx + chunk_size / 2)
                rb(&stacks->b);
            min_idx++;
        }
        else
            rotate_to_closest_in_chunk(&stacks->a, limit);
    }
    while (stacks->b)
    {
        max_pos = find_max_position(stacks->b);
        b_size = stack_size(stacks->b);
        if (max_pos <= b_size / 2)
        {
            while (max_pos-- > 0)
                rb(&stacks->b);
        }
        else
        {
            dist = b_size - max_pos;
            while (dist-- > 0)
                rrb(&stacks->b);
        }
        pa(&stacks->a, &stacks->b);
    }
}
