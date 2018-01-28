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

func updateChecker(num int, checker *int) {
	*checker = (*checker) ^ num
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

	checker, sum, min := 0, 0, 987654321
	for _, num := range nums {
		updateChecker(num, &checker)
		if num < min {
			min = num
		}
		sum += num
	}

	ans := 0
	if checker == 0 {
		ans = sum - min
	}
	fmt.Printf("%d\n", ans)
}
