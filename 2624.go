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

type coins []*coin

type coin struct {
	val int
	num int
}

func newCoin(val, num int) *coin {
	return &coin{val, num}
}

type byVal []*coin

func (bv byVal) Less(i, j int) bool {
	return bv[j].val < bv[i].val
}

func (bv byVal) Len() int {
	return len(bv)
}

func (bv byVal) Swap(i, j int) {
	bv[i], bv[j] = bv[j], bv[i]
}

func getNums(i, remains int, cs coins, dp [][]int) int {
	if remains == 0 {
		return 1
	}
	restSum := 0
	for _, c := range cs[i:] {
		restSum += c.num * c.val
	}
	if remains < 0 || i >= len(cs) || restSum < remains {
		return 0
	}
	if dp[i][remains] > 0 {
		return dp[i][remains]
	}

	sum := 0
	val, num := cs[i].val, cs[i].num
	for j := 0; j <= num; j++ {
		nextRemains := remains - val*j
		sum += getNums(i+1, nextRemains, cs, dp)
	}
	dp[i][remains] = sum
	return sum
}

func main() {
	s := bufio.NewScanner(os.Stdin)
	var T, k int
	fmt.Sscanf(readLine(s), "%d", &T)
	fmt.Sscanf(readLine(s), "%d", &k)
	cs := make(coins, k)
	for i := 0; i < k; i++ {
		var p, n int
		fmt.Sscanf(readLine(s), "%d %d", &p, &n)
		cs[i] = newCoin(p, n)
	}

	sort.Sort(byVal(cs))

	dp := make([][]int, k)
	for i := 0; i < k; i++ {
		dp[i] = make([]int, T+1)
	}
	ans := getNums(0, T, cs, dp)
	fmt.Printf("%d\n", ans)
}
