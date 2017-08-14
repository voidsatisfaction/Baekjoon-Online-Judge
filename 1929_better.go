package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	var M, N int
	fmt.Scanf("%d %d", &M, &N)
	nums := make([]bool, N+1)
	out := bufio.NewWriter(os.Stdout)
	for i := 2; i < N+1; i++ {
		if nums[i] {
			continue
		}
		if i >= M {
			fmt.Fprintln(out, i)
		}
		for j := i * 2; j <= N; j += i {
			nums[j] = true
		}
	}
	out.Flush()
}
