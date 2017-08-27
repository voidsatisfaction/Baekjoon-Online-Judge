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
	dp := []int{0, 0, 1, 1}

	fmt.Scanf("%d", &X)
	for i := 4; i < X+1; i++ {
		if i%6 == 0 {
			dp = append(dp, min(dp[i/3], dp[i/2], dp[i-1])+1)
		} else if i%3 == 0 {
			dp = append(dp, min(dp[i/3], dp[i-1], MAX)+1)
		} else if i%2 == 0 {
			dp = append(dp, min(dp[i/2], dp[i-1], MAX)+1)
		} else {
			dp = append(dp, min(dp[i-1], MAX, MAX)+1)
		}
	}

	fmt.Printf("%d\n", dp[X])
}
