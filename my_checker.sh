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
	printf ' %s' "$@"
	printf '\n'
	wait_for_enter
	"$@"
}

run_shell_test()
{
	local description="$1"
	local command="$2"
	print_separator
	printf '%b\n' "${cyan}>>> $description${reset}"
	printf '%b\n' "Command: $command"
	wait_for_enter
	bash -c "$command"
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
