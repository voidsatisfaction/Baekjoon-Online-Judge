package main

import "fmt"

const mod int = 1000000000

func main() {
	var N int
	k, flag := 10, 1<<10
	fmt.Scanf("%d", &N)

	dp := make([][][]int, N+1)
	for i := 1; i <= N; i++ {
		dp[i] = make([][]int, k)
		for j := 0; j < k; j++ {
			dp[i][j] = make([]int, flag)
		}
	}

	for i := 1; i < k; i++ {
		dp[1][i][1<<uint(i)] = 1
	}

	for i := 1; i < N; i++ {
		for j := 0; j < k; j++ {
			for l := 0; l < flag; l++ {
				switch j {
				case 0:
					dp[i+1][j+1][l|(1<<uint(j+1))] = (dp[i+1][j+1][l|(1<<uint(j+1))] + dp[i][j][l]) % mod
				case 9:
					dp[i+1][j-1][l|(1<<uint(j-1))] = (dp[i+1][j-1][l|(1<<uint(j-1))] + dp[i][j][l]) % mod
				default:
					dp[i+1][j+1][l|(1<<uint(j+1))] = (dp[i+1][j+1][l|(1<<uint(j+1))] + dp[i][j][l]) % mod
					dp[i+1][j-1][l|(1<<uint(j-1))] = (dp[i+1][j-1][l|(1<<uint(j-1))] + dp[i][j][l]) % mod
				}
			}
		}
	}

	ans := 0
	for i := 0; i < k; i++ {
		ans = (ans + dp[N][i][flag-1]) % mod
	}

	fmt.Printf("%d\n", ans)
}
