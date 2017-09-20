package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func stringSliceToInt(sSlice []string) ([]int, error) {
	iSlice := make([]int, 0, len(sSlice))
	for _, s := range sSlice {
		v, err := strconv.Atoi(s)
		if err != nil {
			return nil, err
		}
		iSlice = append(iSlice, v)
	}
	return iSlice, nil
}

func dfs(n int, st *[][]int, visited *[]bool, ans *[]int) {
	(*visited)[n] = true
	for _, nextN := range (*st)[n] {
		if (*visited)[nextN] {
			continue
		}
		dfs(nextN, st, visited, ans)
	}
	(*ans) = append(*ans, n)
}

func main() {
	s := bufio.NewScanner(os.Stdin)
	p := bufio.NewWriter(os.Stdout)
	var N, M int
	fmt.Scanf("%d %d", &N, &M)

	st := make([][]int, N+1)
	visited := make([]bool, N+1)
	ans := make([]int, 0, N)

	for i := 0; i < M; i++ {
		s.Scan()
		input, _ := stringSliceToInt(strings.Split(s.Text(), " "))
		a, b := input[0], input[1]
		st[a] = append(st[a], b)
	}

	for i := 1; i < N+1; i++ {
		if !visited[i] {
			dfs(i, &st, &visited, &ans)
		}
	}

	for i := N - 1; i >= 0; i-- {
		fmt.Fprintf(p, "%d ", ans[i])
	}
	p.Flush()
}
