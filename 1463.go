package main

import (
	"fmt"
)

func min(a int, b int, c int) int {
	if a < b && a < c {
		return a
	} else if b < c {
		return b
	}
	return c
}

func main() {
	var X int
	MAX := 1000000 + 1
	dp := make([]int, MAX)
	dp[2] = 1
	dp[3] = 1

	fmt.Scanf("%d", &X)
	for i := 4; i < X+1; i++ {
		if i%6 == 0 {
			dp[i] = min(dp[i/3], dp[i/2], dp[i-1]) + 1
		} else if i%3 == 0 {
			dp[i] = min(dp[i/3], dp[i-1], MAX) + 1
		} else if i%2 == 0 {
			dp[i] = min(dp[i/2], dp[i-1], MAX) + 1
		} else {
			dp[i] = min(dp[i-1], MAX, MAX) + 1
		}
	}

	fmt.Printf("%d\n", dp[X])
}
