#include "../include/push_swap.h"
#include <stdlib.h>

int main(int argc, char **argv)
{
    t_stacks stacks;

    stacks.a = parse_arguments(argc, argv);
    stacks.b = NULL;
    if (!stacks.a)
        return (0);
    assign_indices(stacks.a);
    if (!stack_sorted(stacks.a))
    {
        if (stack_size(stacks.a) <= 5)
            sort_small(&stacks);
        else
            sort_medium(&stacks);
    }
    free_stack(stacks.a);
    return (0);
}
