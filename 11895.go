package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func readLine(r *bufio.Reader) string {
	str, _ := r.ReadString('\n')
	return strings.TrimSpace(str)
}

func updateChecker(num int, checker []bool) {
	i := 0
	for num > 0 {
		bit := num % 2
		if bit == 1 {
			checker[i] = !checker[i]
		}
		num /= 2
		i++
	}
}

func canGet(checker []bool) bool {
	for _, b := range checker {
		if b {
			return false
		}
	}
	return true
}

func main() {
	r := bufio.NewReader(os.Stdin)
	var n int
	fmt.Sscanf(readLine(r), "%d", &n)
	input := readLine(r)
	inputSlice := strings.Split(input, " ")
	nums := make([]int, 0, len(inputSlice))
	for _, cp := range inputSlice {
		num, _ := strconv.Atoi(cp)
		nums = append(nums, num)
	}

	checker := make([]bool, 20)
	sum, min := 0, 987654321
	for _, num := range nums {
		updateChecker(num, checker)
		if num < min {
			min = num
		}
		sum += num
	}

	ans := 0
	if canGet(checker) {
		ans = sum - min
	}
	fmt.Printf("%d\n", ans)
}
