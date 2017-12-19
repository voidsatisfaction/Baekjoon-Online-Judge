package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	r := bufio.NewReader(os.Stdin)

	var N, M int
	fmt.Scanf("%d %d", &N, &M)
	row := make([]bool, N+1)
	col := make([]bool, M+1)
	for i := 1; i <= N; i++ {
		input, _ := r.ReadString('\n')
		input = strings.TrimSpace(input)
		for j := 1; j <= M; j++ {
			if input[j-1] == 'X' {
				row[i] = true
				col[j] = true
			}
		}
	}

	ans := 0
	for i := 1; i <= N; i++ {
		for j := 1; j <= M; j++ {
			if !col[j] && !row[i] {
				row[i] = true
				col[j] = true
				ans++
			}
		}
	}
	for i := 1; i <= M; i++ {
		if !col[i] {
			ans++
		}
	}
	for i := 1; i <= N; i++ {
		if !row[i] {
			ans++
		}
	}

	fmt.Printf("%d\n", ans)
}
