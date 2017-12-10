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

	wl1 := len(w1)
	wl2 := len(w2)
	longerWl := 0
	if wl1 > wl2 {
		longerWl = wl1
	} else {
		longerWl = wl2
	}

	dp := make([][]int, longerWl+1)
	for i := 0; i <= longerWl; i++ {
		dp[i] = make([]int, longerWl+1)
	}

	ans := 0
	for i := 0; i < len(w1); i++ {
		for j := 0; j < len(w2); j++ {
			if w1[i] == w2[j] {
				dp[i+1][j+1] = dp[i][j] + 1
				if dp[i+1][j+1] > ans {
					ans = dp[i+1][j+1]
				}
			}
		}
	}

	fmt.Printf("%d\n", ans)
}
