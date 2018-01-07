package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func readLine(s *bufio.Scanner) string {
	s.Scan()
	return s.Text()
}

func abs(n int) int {
	if n < 0 {
		return -n
	}
	return n
}

func createSum(a, b []int) []int {
	n := len(a)
	sum := make([]int, 0, n*n)
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			s := a[i] + b[j]
			sum = append(sum, s)
		}
	}

	return sum
}

func main() {
	s := bufio.NewScanner(os.Stdin)
	var N int
	fmt.Sscanf(readLine(s), "%d\n", &N)

	aSlice := make([]int, 0, N)
	bSlice := make([]int, 0, N)
	cSlice := make([]int, 0, N)
	dSlice := make([]int, 0, N)
	for i := 0; i < N; i++ {
		var a, b, c, d int
		fmt.Sscanf(readLine(s), "%d %d %d %d", &a, &b, &c, &d)
		aSlice = append(aSlice, a)
		bSlice = append(bSlice, b)
		cSlice = append(cSlice, c)
		dSlice = append(dSlice, d)
	}

	abSum := createSum(aSlice, bSlice)
	cdSum := createSum(cSlice, dSlice)

	sort.Ints(cdSum)

	cdNewSum := make([]int, 0, len(cdSum))
	cdSumMap := make(map[int]int)
	for i := 0; i < len(cdSum); i++ {
		cur := cdSum[i]
		if i >= 1 {
			bef := cdSum[i-1]
			if cur == bef {
				cdSumMap[cur]++
				continue
			}
		}
		cdSumMap[cur] = 1
		cdNewSum = append(cdNewSum, cur)
	}

	ans := 0
	for _, num := range abSum {
		if v, ok := cdSumMap[-num]; ok {
			ans += v
		}
	}

	fmt.Printf("%d\n", ans)
}
