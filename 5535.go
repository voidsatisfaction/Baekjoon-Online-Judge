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

type byQuality []*cloth

func (bq byQuality) Less(i, j int) bool {
	return bq[i].quality < bq[j].quality
}

func (bq byQuality) Len() int {
	return len(bq)
}

func (bq byQuality) Swap(i, j int) {
	bq[i], bq[j] = bq[j], bq[i]
}

type cloth struct {
	low     int
	high    int
	quality int
}

func newCloth(low, high, quality int) *cloth {
	return &cloth{low, high, quality}
}

func main() {
	s := bufio.NewScanner(os.Stdin)
	var D, N int
	fmt.Sscanf(readLine(s), "%d %d", &D, &N)

	temp := make([]int, 0, D)
	for i := 0; i < D; i++ {
		var t int
		fmt.Sscanf(readLine(s), "%d", &t)
		temp = append(temp, t)
	}

	cs := make([]*cloth, 0, N)
	for i := 0; i < N; i++ {
		var l, h, q int
		fmt.Sscanf(readLine(s), "%d %d %d", &l, &h, &q)
		cs = append(cs, newCloth(l, h, q))
	}

	sort.Sort(byQuality(cs))

	daySelect := make([][]int, D)
	for i, t := range temp {
		lastIndex := -1
		for _, c := range cs {
			low, high, quality := c.low, c.high, c.quality
			if t >= low && t <= high && (lastIndex < 0 || daySelect[i][lastIndex] != quality) {
				daySelect[i] = append(daySelect[i], quality)
				lastIndex++
			}
		}
	}

	dp := make([][]int, D)
	dp[0] = make([]int, N)
	for i := 1; i < D; i++ {
		dp[i] = make([]int, len(daySelect[i]))
		for j, nowQ := range daySelect[i] {
			max := -1
			for beforeIndex, beforeQ := range daySelect[i-1] {
				diff := abs(nowQ - beforeQ)
				if dp[i-1][beforeIndex]+diff > max {
					max = dp[i-1][beforeIndex] + diff
				}
			}
			dp[i][j] = max
		}
	}

	ans := 0
	for _, v := range dp[D-1] {
		if v > ans {
			ans = v
		}
	}
	fmt.Printf("%d\n", ans)
}
