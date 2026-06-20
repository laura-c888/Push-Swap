# Push Swap

*This project was developed by laura Chehbi (`lchehbi`) and Adèle Dufourcq (`addufour`).*

## Overview

`push_swap` is an algorithmic project from the 42 Common Core curriculum. The goal is to sort a stack of integers using a limited set of stack operations while generating the smallest possible number of instructions.

This implementation extends the traditional Push_swap project with an adaptive sorting system capable of selecting different sorting strategies depending on the size and disorder level of the input.

## Features

### Parsing & Validation
- Integer parsing
- Duplicate detection
- Overflow protection
- Error handling
- Memory-safe input processing

### Sorting Strategies
- **Simple**
  - Used for very small inputs
  - `size <= 5`
  - Algorithm: `mini_sort`
- **Adaptive**
  - Used for nearly sorted stacks
  - `disorder < 0.2`
  - Algorithm: `nearly_sorted_sort`
- **Medium**
  - Used for moderately disordered inputs
  - `0.2 <= disorder < 0.5`
  - Algorithm: `chunk_sort`
- **Complex**
  - Used for highly disordered inputs
  - `disorder >= 0.5`
  - Algorithm: `radix_sort`

## Disorder Metric

Before sorting, the program evaluates the disorder level of the stack.
The metric is based on inversion counting:

```c
// disorder = inversions / total_pairs
```

Where:
- `0.0` → already sorted
- `1.0` → completely reversed

This allows the adaptive system to choose the most appropriate sorting strategy.

## Operations

Supported stack operations:
- Swap: `sa`, `sb`, `ss`
- Push: `pa`, `pb`
- Rotate: `ra`, `rb`, `rr`
- Reverse Rotate: `rra`, `rrb`, `rrr`

## Benchmark Mode

An optional benchmark mode provides detailed information about the execution:
- Input size
- Selected strategy
- Disorder level
- Adaptive regime
- Operation counters
- Total operations

## Compilation

Use the included `Makefile` commands:

```sh
make         # compile the project
make clean   # clean object files
make fclean  # remove object files and executable
make re      # rebuild the project
```

## Usage

Sort a stack:

```sh
./push_swap 2 1 3 6 5 8
```

Run with benchmark mode:

```sh
./push_swap --bench 2 1 3 6 5 8
```

## Authors

- Nora Chehbi
- Adèle Dufourcq

## Learning Objectives

This project focuses on:
- Linked lists
- Stack manipulation
- Sorting algorithms
- Complexity analysis
- Adaptive algorithm selection
- Memory management
- Low-level optimization
- Defensive programming

This project was developed as part of the 42 Common Core curriculum.
