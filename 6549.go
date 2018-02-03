package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func readLine(r *bufio.Reader) string {
	str, _ := r.ReadString('\n')
	return strings.TrimSpace(str)
}

func mapToInt(ss []string) []int {
	is := make([]int, len(ss))
	for i, str := range ss {
		n, _ := strconv.Atoi(str)
		is[i] = n
	}
	return is
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

type segmentTree []int

func newSegmentTree(nums []int) segmentTree {
	// min index segmentTree
	n := len(nums)
	st := make(segmentTree, 4*n)
	st.init(0, n-1, 1, nums)
	return st
}

func (segTree segmentTree) init(st, ed, node int, nums []int) int {
	if st == ed {
		segTree[node] = st
		return st
	}

	mid := (st + ed) / 2
	leftIndex := segTree.init(st, mid, 2*node, nums)
	rightIndex := segTree.init(mid+1, ed, 2*node+1, nums)
	if nums[leftIndex] < nums[rightIndex] {
		segTree[node] = leftIndex
	} else {
		segTree[node] = rightIndex
	}
	return segTree[node]
}

func (segTree segmentTree) Get(st, ed, tst, ted, node int, nums []int) int {
	if tst <= st && ted >= ed {
		return segTree[node]
	}

	if st > ted || ed < tst {
		return -1
	}

	mid := (st + ed) / 2
	leftIndex := segTree.Get(st, mid, tst, ted, 2*node, nums)
	rightIndex := segTree.Get(mid+1, ed, tst, ted, 2*node+1, nums)
	if leftIndex == -1 {
		return rightIndex
	} else if rightIndex == -1 {
		return leftIndex
	}

	if nums[leftIndex] < nums[rightIndex] {
		return leftIndex
	}
	return rightIndex
}

func (segTree segmentTree) GetMaxRectangleArea(st, ed int, heights []int) int {
	m := segTree.Get(0, len(heights)-1, st, ed, 1, heights)
	area := heights[m] * (ed - st + 1)

	if st <= m-1 {
		area = max(area, segTree.GetMaxRectangleArea(st, m-1, heights))
	}
	if ed >= m+1 {
		area = max(area, segTree.GetMaxRectangleArea(m+1, ed, heights))
	}
	return area
}

func main() {
	r := bufio.NewReader(os.Stdin)
	p := bufio.NewWriter(os.Stdout)
	for {
		inputSlice := strings.Split(readLine(r), " ")
		intSlice := mapToInt(inputSlice)
		if intSlice[0] == 0 {
			break
		}
		heights := intSlice[1:]
		st := newSegmentTree(heights)
		maxArea := st.GetMaxRectangleArea(0, len(heights)-1, heights)
		fmt.Fprintf(p, "%d\n", maxArea)
	}
	p.Flush()
}
