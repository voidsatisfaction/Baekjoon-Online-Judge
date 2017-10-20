package main

import "fmt"

func main() {
	var T, N, M int
	fmt.Scanf("%d", &T)
	for i := 0; i < T; i++ {
		fmt.Scanf("%d %d", &N, &M)
		dp := make([][]int, 31)
		for j := 0; j < 31; j++ {
			for k := 0; k < 31; k++ {
				dp[j] = append(dp[j], 0)
			}
		}

		for j := 1; j <= N; j++ {
			for k := j; k <= M; k++ {
				if j == 1 {
					dp[j][k] = k
				} else {
					n := j
					m := k
					for m >= j {
						dp[j][k] += dp[n-1][m-1]
						m--
					}
				}
			}
		}
		fmt.Printf("%d\n", dp[N][M])
	}
}
