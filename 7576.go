package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func readLine(r *bufio.Reader) string {
	l, _ := r.ReadString('\n')
	return strings.TrimSpace(l)
}

func spreadTomato(box [][]int, newTomatoSet map[string]bool, M, N, m, n int) map[string]bool {
	dir := []bool{true, true, true, true} // up, down, right, left
	if m == M-1 || box[n][m+1] != 0 {
		dir[2] = false
	}
	if m == 0 || box[n][m-1] != 0 {
		dir[3] = false
	}
	if n == 0 || box[n-1][m] != 0 {
		dir[0] = false
	}
	if n == N-1 || box[n+1][m] != 0 {
		dir[1] = false
	}

	for i, dirVal := range dir {
		var p string
		if dirVal {
			switch i {
			case 0:
				p = fmt.Sprintf("%d:%d", m, n-1)
				box[n-1][m] = 1
			case 1:
				p = fmt.Sprintf("%d:%d", m, n+1)
				box[n+1][m] = 1
			case 2:
				p = fmt.Sprintf("%d:%d", m+1, n)
				box[n][m+1] = 1
			case 3:
				p = fmt.Sprintf("%d:%d", m-1, n)
				box[n][m-1] = 1
			}
			newTomatoSet[p] = true
		}
	}

	return newTomatoSet
}

func bfs(box [][]int, M, N int) int {
	tomatoSet := make(map[string]bool)
	for i := 0; i < M; i++ {
		for j := 0; j < N; j++ {
			if box[j][i] == 1 {
				tomato := fmt.Sprintf("%d:%d", i, j)
				tomatoSet[tomato] = true
			}
		}
	}

	days := 0
	for len(tomatoSet) > 0 {
		newTomatoSet := make(map[string]bool)
		for t := range tomatoSet {
			tSlice := strings.Split(t, ":")
			mStr, nStr := tSlice[0], tSlice[1]
			m, _ := strconv.Atoi(mStr)
			n, _ := strconv.Atoi(nStr)
			newTomatoSet = spreadTomato(box, newTomatoSet, M, N, m, n)
		}
		tomatoSet = newTomatoSet
		days++
	}
	days--

	stop := false
	for i := 0; i < M; i++ {
		for j := 0; j < N; j++ {
			if box[j][i] == 0 {
				days = -1
				stop = true
				break
			}
		}
		if stop {
			break
		}
	}

	return days
}

func main() {
	r := bufio.NewReader(os.Stdin)
	var M, N int
	fmt.Scanf("%d %d", &M, &N)

	box := make([][]int, N)
	for i := 0; i < N; i++ {
		box[i] = make([]int, M)
		inputSlice := strings.Split(readLine(r), " ")
		for j, cp := range inputSlice {
			n, _ := strconv.Atoi(cp)
			box[i][j] = n
		}
	}

	ans := bfs(box, M, N)
	fmt.Printf("%d\n", ans)
}
