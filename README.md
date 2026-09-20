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

Selection sort used as a helper to give every given integer a target index in sorted stack.
Every node of linked list consists of value (integer to be sorted) and that index (target position in stack A)

### Simple strategy

Selection sort which compares current top integer with minimum found by indexing. First we rotate or reverse rotate (depending what requires less operations) until it's on top and then we push it to b. Stack b will be sorted in descending order. After pushing everything to stack A we'll get integers sorted in ascending order.

#### Complexity

The algorithm finds and moves one smallest index during each of `n` passes. Each pass can scan or rotate up to `n` elements, so the total number of operations is O(n<sup>2</sup>).

Sources:\
[Selection sort geeks4geeks](https://www.geeksforgeeks.org/dsa/selection-sort-algorithm-2/)

### Medium strategy

The medium strategy uses a chunk-based sorting algorithm. The indexed values are divided into ranges(chunks). Elements belonging to the current chunk are pushed from stack `a` to stack `b` - other are rotated inside a. Smaller indexed elements are rotated inside `b` so that the values remain positioned efficiently.

After all elements have been moved to stack `b`, the algorithm repeatedly finds the largest index in `b`, rotates it to the top using the shortest direction, and pushes it back to `a`. This produces stack `a` in ascending order.

#### Complexity

The values are processed in chunks of approximately √n elements, so there are about √n chunks. Each element is processed through a bounded number of chunk operations, giving an approximate total complexity of O(n√n).


### Complex strategy

Radix sort implemented using bitwise operation and indexing. The algorithm scans all `n` elements once **for each bit** starting from least significant [*LSD*] with `>>` and `&` bitwise operations.\
If that bit is equal to `0` they are pushed to b. After that those elements are pushed back to a.Everything is repeated until every significant bit is compared.

#### Complexity
Before sorting, every value is replaced by an index between `0` and `n - 1`, so the original 32-bit integer representation is no longer used. Representing these indexes requires approximately `log₂(n)` bits.
The algorithm processes every element once for each bit in its index (`n` operations). So the total complexity is O(n log n).

Sources:\
[Bitwise operations](https://en.wikipedia.org/wiki/Bitwise_operations_in_C)\
[How radix sorting works video](https://www.youtube.com/watch?v=mVRHvZF8xtg&pp=ygUKcmFkaXggc29ydA%3D%3D)\
[How radix sorting works wiki](https://en.wikipedia.org/wiki/Radix_sort)

### Adaptive strategy

If no flags forcing startegy were passed, one of the sorting strategies above is chosen based on disorder computed in `computed_disorder.c`\
There are strict rules from the subject when particular strategies have to be chosen. It was shown in the table below:

| Strategy | Disorder min | Disorder max |
|----------|--------------|--------------|
| Simple   | >0%          | <20%         |
| Medium   | 20%          | <50%         |
| Complex  | 50%          | 100%         |

#### Complexity

The algorithm first compares each pair of elements to calculate disorder, which takes O(n<sup>2</sup>) time. It then runs the selected strategy, so adaptive sorting keeps that strategy's complexity in addition to the disorder calculation.

## Project goal

- Create a program named `push_swap`
- Program which will print a set of restricted operations to sort given integer numbers
- Respect the 42 Norminette rules and The Norm V4

## Collaboration

| Contributor | Responsibilities |
|-------------|------------------|
| skovlekj | Project setup, input validation, sorting strategies (medium), Refactoring/Cleanup and git control flow. |
| jziental | Indexing, disorder calculation, argument parsing, sorting strategies (simple, complex, adaptive), benchmarking, and performance testing. |
| Both contributors | Algorithm discussions, debugging, manual testing, Norm checks, and final integration. |

## Intructions

A standard build produces the executable file `push_swap`:

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
_**flags**_ have to be typed \_**first**\_then only integer arguments

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

This whole project was created with collaborative effort of jziental, skovlekj with AI and other 42 peers assistance. \
AI was used to clarify algorithmic complexity, improve README explanations,
suggest testing methods, and help investigate debugging questions. All generated
suggestions were reviewed, tested, and adapted by both learners.

### Authors tests

| No. | Test | Description / expected result |
|-----|------|-------------|
| 1 | `./push_swap` | No arguments; expected output is empty. |
| 2 | `./push_swap 1` | One sorted integer; expected output is empty. |
| 3 | `./push_swap 3 2` | Sort two reversed integers. |
| 4 | `./push_swap 3 2 1` | Sort three reversed integers. |
| 5 | `./push_swap 1 3 2 4` | Sort four integers with one local inversion. |
| 6 | `./push_swap 6 1 5 2 4 3` | Sort six mixed integers. |
| 7 | `for strategy in simple medium complex adaptive; do ...; done` | One interactive runner step covering 24 sorted benchmark cases; each command is printed before execution, benchmark data stays visible on stderr, and stdout is counted. |
| 8 | `./push_swap --bench --simple 6 1 5 2 4 3 \| wc -l` | Show simple-strategy benchmark data and count its stdout operations. |
| 9 | `./push_swap --bench --medium 6 1 5 2 4 3 \| wc -l` | Show medium-strategy benchmark data and count its stdout operations. |
| 10 | `./push_swap --bench --complex 6 1 5 2 4 3 \| wc -l` | Show complex-strategy benchmark data and count its stdout operations. |
| 11 | `./push_swap --bench --adaptive 6 1 5 2 4 3 \| wc -l` | Show adaptive-strategy benchmark data and count its stdout operations. |
| 12 | `./push_swap --simple 6 1 5 2 4 3 \| wc -l` | Force simple sorting and print only the operation count. |
| 13 | `./push_swap --medium 6 1 5 2 4 3 \| wc -l` | Force medium sorting and print only the operation count. |
| 14 | `./push_swap --complex 6 1 5 2 4 3 \| wc -l` | Force complex sorting and print only the operation count. |
| 15 | `./push_swap --adaptive 6 1 5 2 4 3 \| wc -l` | Force adaptive sorting and print only the operation count. |
| 16 | `./push_swap --bench --mistake` | Invalid flag; expected result is `Error` on stderr. |
| 17 | `./push_swap --bench --simple` | Only flags and no integers; expected result is `Error` on stderr. |
| 18 | `./push_swap --bench 1 2, 3` | Comma in an integer argument; expected result is `Error` on stderr. |
| 19 | `./push_swap 1 1 2` | Duplicate integer; expected result is `Error` on stderr. |
| 20 | `./push_swap 1 2 -3444555666` | Value below `INT_MIN`; expected result is `Error` on stderr. |
| 21 | `./push_swap 1 2 3444555666` | Value above `INT_MAX`; expected result is `Error` on stderr. |
| 22 | `./push_swap 1 2 +` | Sign without digits; expected result is `Error` on stderr. |
| 23 | `./push_swap 1 2 abc` | Non-numeric argument; expected result is `Error` on stderr. |
| 24 | `./push_swap 1 2 +3` | Valid plus sign; the input should be accepted and sorted. |
| 25 | `./push_swap 1 2 -3` | Valid minus sign; the input should be accepted and sorted. |
| 26 | `./push_swap --bench --simple --complex --medium 6 1 5 2 4 3` | Multiple strategy flags are accepted; the last flag, `--medium`, is used and benchmark data is printed. |
| 27 | `./push_swap "-3 -2 -1" 5 7 -513 "213 " \| ./checker_linux "-3 -2 -1" 5 7 -513 "213 "` | Check quoted arguments and whitespace handling; expected result is `OK`. |
| 28 | `./push_swap --simple 1 2 3 \| ./checker_linux 1 2 3` | Send simple-strategy output to the checker; expected result is `OK`. |
| 29 | `./push_swap --medium 6 1 5 2 4 3 \| ./checker_linux 6 1 5 2 4 3` | Send medium-strategy output to the checker; expected result is `OK`. |
| 30 | `./push_swap --complex 6 1 5 2 4 3 \| ./checker_linux 6 1 5 2 4 3` | Send complex-strategy output to the checker; expected result is `OK`. |
| 31 | `./push_swap --adaptive 6 1 5 2 4 3 \| ./checker_linux 6 1 5 2 4 3` | Send adaptive-strategy output to the checker; expected result is `OK`. |
| 32 | `shuf -i 0-9999 -n 100 > args.txt; ./push_swap $(cat args.txt) \| wc -l` | Generate 100 random integers and count the produced operations. |
| 33 | `shuf -i 0-9999 -n 500 > args.txt; ./push_swap $(cat args.txt) \| wc -l` | Generate 500 random integers and count the produced operations. |
| 34 | `shuf -i 0-9999 -n 500 > args.txt; ./push_swap $(cat args.txt) \| ./checker_linux $(cat args.txt)` | Verify adaptive sorting of 500 random integers with the checker. |
| 35 | `shuf -i 0-9999 -n 500 > args.txt; ./push_swap --bench $(cat args.txt) 2>bench.txt \| ./checker_linux $(cat args.txt)` | Verify sorting and confirm benchmark data is written to `bench.txt` on stderr. |
| 36 | `q` at any runner prompt | Stop the complete test run without closing the terminal. |

The runner prints a separator, the test title, and the command, then waits for
Enter before executing the test. Type `q` and press Enter at any prompt to stop
the complete test run.

```sh
(
if [ -t 1 ]; then
	cyan='\033[1;36m'
	magenta='\033[1;35m'
	yellow='\033[1;33m'
	reset='\033[0m'
else
	cyan=''
	magenta=''
	yellow=''
	reset=''
fi

print_separator()
{
	printf '%b\n' "${cyan}============================================================${reset}"
}

wait_for_enter()
{
	printf '%b' "${yellow}Press Enter to run this test or q to quit...${reset} "
	IFS= read -r answer || exit 0
	case "$answer" in
		q|Q)
			printf '\nTest run stopped.\n'
			exit 0
			;;
	esac
}

run_test()
{
	local description="$1"
	shift
	print_separator
	printf '%b\n' "${cyan}>>> $description${reset}"
	printf 'Command:'
	printf ' %q' "$@"
	printf '\n'
	wait_for_enter
	"$@"
}

run_shell_test()
{
	local description="$1"
	local command="$2"
	print_separator
	printf '%b\nCommand: %s\n' "${cyan}>>> $description${reset}" "$command"
	wait_for_enter
	bash -c "$command"
	printf '\n'
}

# Basic input and sorting cases.
run_shell_test 'No arguments: count operations' './push_swap'
run_shell_test 'One integer: count operations' './push_swap 1'
run_shell_test 'Two integers in reverse order: count operations' './push_swap 3 2'
run_shell_test 'Three integers in reverse order: count operations' './push_swap 3 2 1'
run_shell_test 'Four integers with one local inversion: count operations' './push_swap 1 3 2 4'
run_shell_test 'Six integers in mixed order: count operations' './push_swap 6 1 5 2 4 3 | wc -l'

# Benchmark sorted inputs from one to six integers for every strategy.
run_shell_test 'Benchmark sorted inputs for every strategy' \
	'for strategy in simple medium complex adaptive; do
		for numbers in "1" "1 2" "1 2 3" "1 2 3 4" \
			"1 2 3 4 5" "1 2 3 4 5 6"; do
			printf "\\033[1;35m--- %s: %s ---\\033[0m\\n" "$strategy" "$numbers"
			printf "\\033[1;35mCommand: ./push_swap --bench --%s %s | wc -l\\033[0m\\n" "$strategy" "$numbers"
			./push_swap --bench --$strategy $numbers | wc -l
		done
	done'

# Benchmark and direct strategy selection.
run_shell_test 'Benchmark simple strategy: report and count operations' './push_swap --bench --simple 6 1 5 2 4 3 | wc -l'
run_shell_test 'Benchmark medium strategy: report and count operations' './push_swap --bench --medium 6 1 5 2 4 3 | wc -l'
run_shell_test 'Benchmark complex strategy: report and count operations' './push_swap --bench --complex 6 1 5 2 4 3 | wc -l'
run_shell_test 'Benchmark adaptive strategy: report and count operations' './push_swap --bench --adaptive 6 1 5 2 4 3 | wc -l'
run_shell_test 'Force simple strategy: count operations' './push_swap --simple 6 1 5 2 4 3 | wc -l'
run_shell_test 'Force medium strategy: count operations' './push_swap --medium 6 1 5 2 4 3 | wc -l'
run_shell_test 'Force complex strategy: count operations' './push_swap --complex 6 1 5 2 4 3 | wc -l'
run_shell_test 'Force adaptive strategy: count operations' './push_swap --adaptive 6 1 5 2 4 3 | wc -l'

# Invalid arguments.
run_test 'Invalid flag' ./push_swap --bench --mistake
run_test 'Only flags and no integers' ./push_swap --bench --simple
run_test 'Invalid comma separator' ./push_swap --bench '1' '2,' '3'
run_test 'Duplicate integer' ./push_swap 1 1 2
run_test 'Value below INT_MIN' ./push_swap 1 2 -3444555666
run_test 'Value above INT_MAX' ./push_swap 1 2 3444555666
run_test 'Sign without digits' ./push_swap 1 2 +
run_test 'Non-numeric argument' ./push_swap 1 2 abc

# Valid input and checker verification.
run_test 'Accepted plus sign' ./push_swap 1 2 +3
run_test 'Accepted minus sign' ./push_swap 1 2 -3
run_shell_test 'Last strategy flag wins: show benchmark' './push_swap --bench --simple --complex --medium 6 1 5 2 4 3'
run_shell_test 'Quoted arguments and whitespace handling: checker' \
	'./push_swap "-3 -2 -1" 5 7 -513 "213 " | ./checker_linux "-3 -2 -1" 5 7 -513 "213 "'

# Checker verification.
run_shell_test 'Checker: simple strategy' \
	'./push_swap --simple 1 2 3 | ./checker_linux 1 2 3'
run_shell_test 'Checker: medium strategy' \
	'./push_swap --medium 6 1 5 2 4 3 | ./checker_linux 6 1 5 2 4 3'
run_shell_test 'Checker: complex strategy' \
	'./push_swap --complex 6 1 5 2 4 3 | ./checker_linux 6 1 5 2 4 3'
run_shell_test 'Checker: adaptive strategy' \
	'./push_swap --adaptive 6 1 5 2 4 3 | ./checker_linux 6 1 5 2 4 3'

# Performance and benchmark output.
run_shell_test '100 random integers: count operations' \
	'shuf -i 0-9999 -n 100 > args.txt; ./push_swap $(cat args.txt) | wc -l'
run_shell_test '500 random integers: count operations' \
	'shuf -i 0-9999 -n 500 > args.txt; ./push_swap $(cat args.txt) | wc -l'
run_shell_test '500 random integers: checker verification' \
	'shuf -i 0-9999 -n 500 > args.txt; ./push_swap $(cat args.txt) | ./checker_linux $(cat args.txt)'
run_shell_test '500 random integers: benchmark stays on stderr' \
	'shuf -i 0-9999 -n 500 > args.txt; ./push_swap --bench $(cat args.txt) 2>bench.txt | ./checker_linux $(cat args.txt)'
)
```
