package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func readLine(r *bufio.Reader) string {
	input, _ := r.ReadString('\n')
	return strings.TrimSpace(input)
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func min(nums ...int) int {
	if len(nums) == 1 {
		return nums[0]
	}
	mn := nums[0]
	for _, num := range nums {
		if num < mn {
			mn = num
		}
	}
	return mn
}

func getSum(from, to int, distSum []int) int {
	if from == 0 && to == 0 {
		return 0
	}
	if from == 0 {
		return distSum[to]
	}
	if to == 0 {
		return distSum[from]
	}
	return abs(distSum[to] - distSum[from])
}

func main() {
	r := bufio.NewReader(os.Stdin)
	var n, m int
	fmt.Sscanf(readLine(r), "%d %d", &n, &m)
	inputSlice := strings.Split(readLine(r), " ")
	distSlice := make([]int, 0, len(inputSlice))
	for _, cp := range inputSlice {
		num, _ := strconv.Atoi(cp)
		distSlice = append(distSlice, num)
	}

	distSum := make([]int, 1, len(distSlice)+1)
	sum := 0
	for _, dist := range distSlice {
		sum += dist
		distSum = append(distSum, sum)
	}

	minDist := 1987654321
	for i := 0; i < m; i++ {
		var a, b, c int
		fmt.Sscanf(readLine(r), "%d %d %d", &a, &b, &c)
		if a > b {
			a, b = b, a
		}
		case1 := getSum(0, a, distSum) + c + getSum(b, n, distSum) + getSum(n, a+1, distSum)
		case2 := getSum(0, n, distSum) + 2*c
		case3 := getSum(0, n, distSum) + getSum(a, b, distSum) + c
		case4 := 1987654321
		if a+1 == b {
			case4 = getSum(0, n, distSum) - getSum(a, b, distSum) + c
		}
		case5 := getSum(0, a, distSum) + getSum(a, b-1, distSum) + 2*c + 2*getSum(b, n, distSum)

		minDist = min(
			case1, case2, case3,
			case4, case5, minDist,
		)
	}

	fmt.Printf("%d\n", minDist)
}
