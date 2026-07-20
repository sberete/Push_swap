# Push_swap

A 42 school project that sorts a stack of integers using a limited set of operations and two stacks, while minimizing the number of operations performed. A bonus `checker` program verifies that a given sequence of operations correctly sorts the stack.

## Operations

`push_swap` and `checker` operate on two stacks (`a` and `b`) using the following instructions: `sa`, `sb`, `ss` (swap), `pa`, `pb` (push), `ra`, `rb`, `rr` (rotate), `rra`, `rrb`, `rrr` (reverse rotate).

## Algorithm

Numbers are pushed to stack `b`, split into chunks, and repositioned based on the cheapest combination of rotate/reverse-rotate operations before being pushed back onto stack `a` in sorted order. The cost of each possible move is computed for every number to choose the most efficient path.

## Build

```bash
make        # builds push_swap
make bonus  # builds the checker program
make clean  # removes object files
make fclean # also removes the executables
make re     # rebuilds everything
```

## Usage

```bash
./push_swap 2 1 3 6 5 8
```

Prints the list of operations needed to sort the stack.

```bash
./checker 2 1 3 6 5 8
```

Reads operations from standard input and prints `OK` if the stack ends up sorted, `KO` otherwise.

## Constraints

- Follows the 42 Norm
- Compiles without errors or warnings (`-Wall -Wextra -Werror`)
- Relies on `libft` and `ft_printf` as internal libraries
