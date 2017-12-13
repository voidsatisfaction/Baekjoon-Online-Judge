package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func abs(n int64) int64 {
	if n < 0 {
		return -n
	}
	return n
}

func main() {
	r := bufio.NewReader(os.Stdin)
	var N int
	ans := make([]int64, 3)
	var ansValue int64 = 40000000000
	fmt.Scanf("%d", &N)
	input, _ := r.ReadString('\n')
	strInputSlice := strings.Split(strings.TrimSpace(input), " ")

	nums := make([]int, N)
	for i := 0; i < N; i++ {
		v, _ := strconv.Atoi(strInputSlice[i])
		nums[i] = v
	}

	sort.Ints(nums)

	nums64 := make([]int64, N)
	for i, v := range nums {
		nums64[i] = int64(v)
	}

	for c := N - 1; c >= 2; c-- {
		a := 0
		b := c - 1
		for b > a {
			sum := nums64[a] + nums64[b] + nums64[c]
			sumabs := abs(sum)
			if sumabs < abs(ansValue) {
				ansValue = sum
				ans[0] = nums64[a]
				ans[1] = nums64[b]
				ans[2] = nums64[c]
			}

			if sum > 0 {
				b--
			} else if sum < 0 {
				a++
			} else {
				break
			}
		}
	}

	fmt.Printf("%d %d %d\n", ans[0], ans[1], ans[2])
}
