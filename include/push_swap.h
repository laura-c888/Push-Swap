#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>

typedef struct s_node
{
    int value;
    int index;
    struct s_node *next;
}   t_node;

typedef struct s_stacks
{
    t_node *a;
    t_node *b;
}   t_stacks;

void    error_exit(const char *message);

t_node  *new_node(int value);
void    free_stack(t_node *stack);
int     stack_size(t_node *stack);
bool    stack_sorted(t_node *stack);
void    push_front(t_node **stack, t_node *node);
void    push_bottom(t_node **stack, t_node *node);
t_node  *pop_front(t_node **stack);
t_node  *stack_last(t_node *stack);
t_node  *stack_before_last(t_node *stack);

void    swap(t_node **stack);
void    rotate(t_node **stack);
void    reverse_rotate(t_node **stack);

void    sa(t_node **a);
void    sb(t_node **b);
void    ss(t_node **a, t_node **b);
void    pa(t_node **a, t_node **b);
void    pb(t_node **a, t_node **b);
void    ra(t_node **a);
void    rb(t_node **b);
void    rr(t_node **a, t_node **b);
void    rra(t_node **a);
void    rrb(t_node **b);
void    rrr(t_node **a, t_node **b);

t_node  *parse_arguments(int argc, char **argv);
void    assign_indices(t_node *stack);

void    sort_small(t_stacks *stacks);
void    sort_medium(t_stacks *stacks);

void    print_stack(const char *name, t_node *stack);

#endif
