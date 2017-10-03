package main

import (
	"bufio"
	"fmt"
	"os"
)

var n, m int

func preProcess(findStr string) []int {
	mSlice := make([]int, m)
	j := 0
	for i := 1; i < m; i++ {
		for j > 0 && findStr[i] != findStr[j] {
			j = mSlice[j-1]
		}
		if findStr[i] == findStr[j] {
			j++
			mSlice[i] = j
		}
	}
	return []int{}
}

func main() {
	s := bufio.NewScanner(os.Stdin)
	p := bufio.NewWriter(os.Stdout)
	s.Scan()
	totalStr := s.Text()
	n = len(totalStr)
	s.Scan()
	findStr := s.Text()
	m = len(findStr)

	fmt.Println(totalStr, findStr, n, m)
	p.Flush()
}
