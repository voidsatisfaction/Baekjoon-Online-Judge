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

type nodes []node

type node struct {
	x int
	y int
}

func newNode(x, y int) node {
	return node{
		x, y,
	}
}

func (n node) hashCode() string {
	x, y := n.x, n.y
	return fmt.Sprintf("%d:%d", x, y)
}

type byYX []node

func (yx byYX) Less(i, j int) bool {
	x1, y1 := yx[i].x, yx[i].y
	x2, y2 := yx[j].x, yx[j].y
	if y1 == y2 {
		return x1 < x2
	}
	return y2 < y1
}

func (yx byYX) Len() int {
	return len(yx)
}

func (yx byYX) Swap(i, j int) {
	yx[i], yx[j] = yx[j], yx[i]
}

type byXY []node

func (xy byXY) Less(i, j int) bool {
	x1, y1 := xy[i].x, xy[i].y
	x2, y2 := xy[j].x, xy[j].y
	if x1 == x2 {
		return y2 < y1
	}
	return x1 < x2
}

func (xy byXY) Len() int {
	return len(xy)
}

func (xy byXY) Swap(i, j int) {
	xy[i], xy[j] = xy[j], xy[i]
}

type segmentTree []int

func segmentTreeNew(nodes []node) segmentTree {
	n := len(nodes)
	segTree := make([]int, 4*n)

	segTree[1] = getSum(segTree, 0, n-1, 1)

	return segmentTree(segTree)
}

func getSum(segTree []int, st, ed, node int) int {
	if st == ed {
		segTree[node] = 1
		return 1
	}

	mid := (st + ed) / 2
	segTree[node] = getSum(segTree, st, mid, 2*node) + getSum(segTree, mid+1, ed, 2*node+1)
	return segTree[node]
}

func (segTree segmentTree) get(st, ed, tst, ted, node int) int {
	if st >= tst && ed <= ted {
		return segTree[node]
	}

	if tst > ed || ted < st {
		return 0
	}

	mid := (st + ed) / 2
	if ted <= mid {
		return segTree.get(st, mid, tst, ted, 2*node)
	} else if tst >= mid+1 {
		return segTree.get(mid+1, ed, tst, ted, 2*node+1)
	}
	return segTree.get(st, mid, tst, ted, 2*node) + segTree.get(mid+1, ed, tst, ted, 2*node+1)
}

func (segTree segmentTree) update(st, ed, i, newVal, node int) int {
	if st == i && ed == i {
		segTree[node] = newVal
		return newVal
	}

	if i > ed || i < st {
		return 0
	}

	mid := (st + ed) / 2
	if i <= mid {
		segTree[node] = segTree.update(st, mid, i, newVal, 2*node) + segTree[2*node+1]
	} else {
		segTree[node] = segTree[2*node] + segTree.update(mid+1, ed, i, newVal, 2*node+1)
	}
	return segTree[node]
}

func main() {
	s := bufio.NewScanner(os.Stdin)
	p := bufio.NewWriter(os.Stdout)
	var t, n int
	fmt.Sscanf(readLine(s), "%d", &t)
	for i := 0; i < t; i++ {
		fmt.Sscanf(readLine(s), "%d", &n)
		xSortedArray := make(nodes, 0, n)
		ySortedArray := make(nodes, 0, n)
		for j := 0; j < n; j++ {
			var x, y int
			fmt.Sscanf(readLine(s), "%d %d", &x, &y)
			xSortedArray = append(xSortedArray, newNode(x, y))
			ySortedArray = append(ySortedArray, newNode(x, y))
		}
		sort.Sort(byYX(ySortedArray))
		sort.Sort(byXY(xSortedArray))

		xSortedArrayMap := make(map[string]int)
		for i, node := range xSortedArray {
			xSortedArrayMap[node.hashCode()] = i
		}

		segTree := segmentTreeNew(xSortedArray)

		ans := 0
		for _, node := range ySortedArray {
			l := len(ySortedArray) - 1
			key := node.hashCode()
			from, to := xSortedArrayMap[key]+1, l
			if from > to {
				segTree.update(0, l, from-1, 0, 1)
				continue
			}
			ans += segTree.get(0, l, from, to, 1)
			segTree.update(0, l, from-1, 0, 1)
		}
		fmt.Fprintf(p, "%d\n", ans)
	}
	p.Flush()
}
