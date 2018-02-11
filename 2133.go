package main

import "fmt"

func main() {
	var N int
	fmt.Scanf("%d", &N)

	if N%2 != 0 {
		fmt.Printf("%d\n", 0)
		return
	}

	dp := []int{1, 3}
	n := N / 2
	i := 1
	sum := 2
	for len(dp) < n+1 {
		an := 3*dp[i] + sum
		dp = append(dp, an)
		sum += 2 * dp[i]
		i++
	}
	fmt.Printf("%d\n", dp[n])
}
