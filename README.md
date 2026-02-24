*This project has been created as part of the 42 curriculum by kevlim.*

# Push_swap

## Description
Push_swap is a 42 project aiming to sort a stack of integers using a limited set of operations (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`) while minimizing the number of operations.
The program takes integers as input (either as separate arguments or a single quoted string), outputs the sequence of operations to sort the stack, and can be tested with `checker_linux` to verify correctness.

## Instructions
- Make
- Run the program as `./push_swap 3 2 1 42` or `./push_swap "3 2 1 42"`.
- To verify sorting: `./push_swap 3 2 1 42 | ./checker_linux 3 2 1 42` (should return `OK`).

- For testing with random numbers:   
`ARGS=$(shuf -i 1-1000 -n 100 | tr '\n' ' ')`  
`./push_swap $ARGS | tee ops.txt | ./checker_linux $ARGS`  
`echo "Number of operations: $(wc -l < ops.txt)"`

## Resources
- Youtube : push_swap tutorial (Thuggonaut)
- GitBook : algorithm complexity
- medium.com : turkish algorithm explaination
- AI : Debug and memory leaks
