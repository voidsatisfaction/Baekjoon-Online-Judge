package main

import (
	"bufio"
	"fmt"
	"os"
)

type value struct {
	min int
	max int
}

func max(nums ...int) int {
	maxNum := nums[0]
	for _, n := range nums {
		if n > maxNum {
			maxNum = n
		}
	}
	return maxNum
}

func min(nums ...int) int {
	minNum := nums[0]
	for _, n := range nums {
		if n < minNum {
			minNum = n
		}
	}
	return minNum
}

func main() {
	s := bufio.NewScanner(os.Stdin)
	var N int
	fmt.Scanf("%d", &N)

	a := make([]value, 3)
	for i := 0; i < N; i++ {
		var x, y, z int
		s.Scan()
		fmt.Sscanf(s.Text(), "%d %d %d", &x, &y, &z)
		firstMax := max(a[0].max, a[1].max) + x
		firstMin := min(a[0].min, a[1].min) + x

		secondMax := max(a[0].max, a[1].max, a[2].max) + y
		secondMin := min(a[0].min, a[1].min, a[2].min) + y

		thirdMax := max(a[1].max, a[2].max) + z
		thirdMin := min(a[1].min, a[2].min) + z

		a[0].max, a[0].min = firstMax, firstMin
		a[1].max, a[1].min = secondMax, secondMin
		a[2].max, a[2].min = thirdMax, thirdMin
	}

	maxValue := max(a[0].max, a[1].max, a[2].max)
	minValue := min(a[0].min, a[1].min, a[2].min)

	fmt.Printf("%d %d\n", maxValue, minValue)
}
