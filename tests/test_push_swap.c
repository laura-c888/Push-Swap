#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/push_swap.h"

static t_node *build_stack(int values[], int count)
{
    t_node *stack;
    int i;

    stack = NULL;
    i = 0;
    while (i < count)
    {
        push_bottom(&stack, new_node(values[i]));
        i++;
    }
    assign_indices(stack);
    return (stack);
}

static void assert_stack_values(t_node *stack, int expected[], int count)
{
    int i;

    i = 0;
    while (i < count)
    {
        assert(stack != NULL);
        assert(stack->value == expected[i]);
        stack = stack->next;
        i++;
    }
    assert(stack == NULL);
}

static void test_parsing(void)
{
    char *argv[] = {"push_swap", "3", "2", "1"};
    t_node *stack;

    stack = parse_arguments(4, argv);
    assert(stack_size(stack) == 3);
    assert(stack->value == 3);
    assert(stack->next->value == 2);
    assert(stack->next->next->value == 1);
    free_stack(stack);

    char *argv2[] = {"push_swap", "3 2 1"};
    stack = parse_arguments(2, argv2);
    assert(stack_size(stack) == 3);
    assert(stack->value == 3);
    assert(stack->next->value == 2);
    assert(stack->next->next->value == 1);
    free_stack(stack);

    char *argv3[] = {"push_swap", "5 4", "3", "2 1"};
    stack = parse_arguments(4, argv3);
    assert(stack_size(stack) == 5);
    assert(stack->value == 5);
    assert(stack->next->value == 4);
    assert(stack->next->next->value == 3);
    assert(stack->next->next->next->value == 2);
    assert(stack->next->next->next->next->value == 1);
    free_stack(stack);
}

static void test_swap_and_rotate(void)
{
    int input[] = {1, 2, 3};
    int expected_swap[] = {2, 1, 3};
    int expected_rotate[] = {1, 3, 2};
    t_node *stack;

    stack = build_stack(input, 3);
    sa(&stack);
    assert_stack_values(stack, expected_swap, 3);
    ra(&stack);
    assert_stack_values(stack, expected_rotate, 3);
    rra(&stack);
    assert_stack_values(stack, expected_swap, 3);
    free_stack(stack);
}

static void test_push_and_pop(void)
{
    int a_values[] = {2, 1};
    int b_values[] = {3};
    t_node *a;
    t_node *b;

    a = build_stack(a_values, 2);
    b = build_stack(b_values, 1);
    pb(&a, &b);
    assert(stack_size(a) == 1);
    assert(stack_size(b) == 2);
    pa(&a, &b);
    assert(stack_size(a) == 2);
    assert(stack_size(b) == 1);
    free_stack(a);
    free_stack(b);
}

static void test_sort_small(void)
{
    int values[] = {3, 1, 2};
    int expected[] = {1, 2, 3};
    t_node *stack;
    t_stacks stacks;

    stack = build_stack(values, 3);
    stacks.a = stack;
    stacks.b = NULL;
    sort_small(&stacks);
    assert_stack_values(stacks.a, expected, 3);
    free_stack(stacks.a);
}

static void test_sort_medium(void)
{
    int values[] = {10, 5, 2, 8, 4, 9, 3, 7, 1, 6};
    int expected[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    t_node *stack;
    t_stacks stacks;

    stack = build_stack(values, 10);
    stacks.a = stack;
    stacks.b = NULL;
    sort_medium(&stacks);
    assert_stack_values(stacks.a, expected, 10);
    free_stack(stacks.a);
}

int main(void)
{
    test_parsing();
    test_swap_and_rotate();
    test_push_and_pop();
    test_sort_small();
    test_sort_medium();
    printf("All push_swap tests passed.\n");
    return (0);
}
