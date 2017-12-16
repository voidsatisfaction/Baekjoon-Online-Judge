package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	const DIV = 1000000
	r := bufio.NewReader(os.Stdin)
	input, _ := r.ReadString('\n')
	enc := strings.TrimSpace(input)
	l := len(enc)
	dp := make([]int, l+1)
	if enc[l-1] != '0' {
		dp[l-1] = 1
	}
	dp[l] = 1
	for i := l - 2; i >= 0; i-- {
		beforeTwoNum, _ := strconv.Atoi(string(enc[i]) + string(enc[i+1]))
		if beforeTwoNum >= 10 && beforeTwoNum <= 26 {
			dp[i] = (dp[i+1] + dp[i+2]) % DIV
		} else if beforeTwoNum < 10 {
			continue
		} else {
			dp[i] = dp[i+1]
		}
	}
	fmt.Printf("%d\n", dp[0])
}
