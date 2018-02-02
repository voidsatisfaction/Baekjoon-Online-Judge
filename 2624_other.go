package main

import (
	"bufio"
	"fmt"
	"os"
)

func readLine(s *bufio.Scanner) string {
	s.Scan()
	return s.Text()
}

type coins []*coin

type coin struct {
	val int
	num int
}

func newCoin(val, num int) *coin {
	return &coin{val, num}
}

func main() {
	s := bufio.NewScanner(os.Stdin)
	var T, k int
	fmt.Sscanf(readLine(s), "%d", &T)
	fmt.Sscanf(readLine(s), "%d", &k)
	cs := make(coins, k)
	for i := 0; i < k; i++ {
		var p, n int
		fmt.Sscanf(readLine(s), "%d %d", &p, &n)
		cs[i] = newCoin(p, n)
	}

	dp := make([]int, T+1)
	dp[0] = 1
	for _, c := range cs {
		val, num := c.val, c.num
		for i := T; i > 0; i-- {
			for j := 1; i-val*j >= 0 && j <= num; j++ {
				dp[i] += dp[i-val*j]
			}
		}
	}

	fmt.Printf("%d\n", dp[T])
}
