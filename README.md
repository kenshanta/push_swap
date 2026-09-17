_This project has been created as part of the 42 curriculum by jziental, skovlekj_

<center>
<h1>Push_swap project
</h1>
</center>

## Description

This project is part of the 42 School curriculum and it one of the first major C team programming exercises of the Common Core. The goal is to create a program whch will generate a set of least possible operations to sort given valid set of integers.Program parses arguments and integers are send to object stack a, whereas stack b is initialized empty.
Valid operations on those stacks are:
- sa (swap a): Swap the first two elements at the top of stack a.
- sb (swap b): Swap the first two elements at the top of stack b.
- ss : sa and sb at the same time.
- pa (push a): Take the first element at the top of b and put it at the top of a.
- pb (push b): Take the first element at the top of a and put it at the top of b.
- ra (rotate a): Shift up all elements of stack a by one.
- rb (rotate b): Shift up all elements of stack b by one.
- rr : ra and rb at the same time.
- rra (reverse rotate a): Shift down all elements of stack a by one.The last element becomes the first one.
- rrb (reverse rotate b): Shift down all elements of stack b by one.The last element becomes the first one.
- rrr : rra and rrb at the same time.

4 startegies of sorting are implemented and a default strategy is to adjust way of sorting to computed disorder metric.
These are:
- --simple forces the use of O(n<sup>2</sup>) algorithm.
- --medium forces the use of O(n√n) algorithm.
- --complex forces the use of O(n log n) algorithm.
- --adaptive (default) forces the use of adaptive algorithm based on disorder.
## Detailed explanation and justification
### Indexing
Selection sort used as a helper to give every given integer a target index in sorted stack
### Simple startegy
Selection sort which compares current top integer with minimum found by indexing
### Medium strategy
### Complex strategy
Radix sort implemented using bitwise operation and indexing

Sources:
[Bitwise operations](https://en.wikipedia.org/wiki/Bitwise_operations_in_C)
[How radix sorting works video] (https://www.youtube.com/watch?v=mVRHvZF8xtg&pp=ygUKcmFkaXggc29ydA%3D%3D)
[How radix sorting works wiki](https://en.wikipedia.org/wiki/Radix_sort)
### Adaptive startegy
One of the sorting strategies above is chosen based on disorder computed in
## Project goal

- Create a program named `push_swap.a`
- Program which will print a set of restricted operations to sort given integer numbers
- Respect the 42 Norminette rules and The Norm V4

# Intructions

A standard build produces the executable file ``push_swap.a``:

```sh
make
```

Useful commands:

```sh
make clean
make fclean
make re
make -s (flag to silence all commands)
```
Running the program:\
_**flags**_ have to be typed _**first**_then only integer arguments
```sh
./push_swap --complex --bench  1 2 3 -54 -42 42 12
```

Test cases are in the section _Authors tests_ at the end of this file
## Repository structure

- `push_swap.h` contains the function prototypes
- Code is stored in a separate `*.c` and `push_swap.h` files
- `README.md` documents the project requirements and usage

# Resources

- [42 Push_swap subject ](https://cdn.intra.42.fr/pdf/pdf/206637/en.subject.pdf)
- [The C standard library reference](https://cppreference.com)
- [GNU _make_ tutorial](https://www.gnu.org/software/make/manual/make.html)
- AI tools as a helper for research, explanations, and inspiration while keeping the implementation verified mainly manually

## Submission requirements

To be accepted by the 42 evaluation system, the project must:

- Compile without warnings with `-Wall -Wextra -Werror`
- Follow the 42 Norminette rules
- Avoid forbidden functions unless explicitly allowed
- Be free of memory leaks
- Provide a complete and correct `ft_*.c`, `push_swap.h`, `README.md` and `Makefile`

## Notes

This whole project was created with collaborative effort of jziental, skovlekj with AI and other 42 peers assistance. Authors checked it thoroughly to ensure it matches the project purpose and the 42 Push_swap Subject requirements.

### Authors tests

```sh
#EDGE CASES
./push_swap 3 2 1	#naive check
./push_swap				#nothing passed
./push_swap --bench --mistake #wrong argument
./push_swap "-3 -2 -1" 5 7 -513 "213 " | ./checker_linux "-3 -2 -1" 5 7 -513 "213 " #taking arguments with and without ""
./push_swap --bench 1 2, 3 #wrong argument - only valid separator is whitespace " "
./push_swap 1 2 3		#already sorted
./push_swap 1 2 -3444555666 # < INT_MIN
./push_swap 1 2 3444555666 #  > INT_MAX
#PERFORMANCE
shuf -i 0-9999 -n 100 > args.txt ; ./push_swap $(cat args.txt) | wc -l #num of operations for 100 random integers from 0 to 9999
shuf -i 0-9999 -n 500 > args.txt ; ./push_swap $(cat args.txt) | wc -l #num of operations for 500 random integers from 0 to 9999
#CHECKER VERIFICATION
shuf -i 0-9999 -n 500 > args.txt ; ./push_swap $(cat args.txt) | ./checker_linux $(cat args.txt) #check if operations are correct for ADAPTIVE
shuf -i 0-9999 -n 500 > args.txt ; ./push_swap --simple $(cat args.txt) | ./checker_linux $(cat args.txt) #check if operations are correct for SIMPLE
shuf -i 0-9999 -n 500 > args.txt ; ./push_swap --medium $(cat args.txt) | ./checker_linux $(cat args.txt) #check if operations are correct for MEDIUM
shuf -i 0-9999 -n 500 > args.txt ; ./push_swap --complex $(cat args.txt) | ./checker_linux $(cat args.txt) #check if operations are correct for COMPLEX
shuf -i 0-9999 -n 500 > args.txt ; ./push_swap --bench $(cat args.txt) 2>bench.txt| ./checker_linux $(cat args.txt) #check if benchmark output is stderr
```
