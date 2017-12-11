package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	r := bufio.NewReader(os.Stdin)
	w1, _ := r.ReadString('\n')
	w2, _ := r.ReadString('\n')
	w1 = strings.TrimSpace(w1)
	w2 = strings.TrimSpace(w2)

	N := len(w1)
	M := len(w2)

	dp := make([][]int, N+1)
	for i := 0; i < N+1; i++ {
		dp[i] = make([]int, M+1)
	}

	for i := 1; i <= N; i++ {
		for j := 1; j <= M; j++ {
			if w1[i-1] == w2[j-1] {
				dp[i][j] = dp[i-1][j-1] + 1
			} else {
				if dp[i][j-1] > dp[i-1][j] {
					dp[i][j] = dp[i][j-1]
				} else {
					dp[i][j] = dp[i-1][j]
				}
			}
		}
	}

	fmt.Printf("%d\n", dp[N][M])
}
