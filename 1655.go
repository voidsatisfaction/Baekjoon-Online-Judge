package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"os"
)

type IntMinHeap struct {
	IntHeap
}

type IntMaxHeap struct {
	IntHeap
}

func (h IntMaxHeap) Less(i, j int) bool {
	return h.IntHeap[i] > h.IntHeap[j]
}

type IntHeap []int

func (h IntHeap) Len() int {
	return len(h)
}

func (h IntHeap) Less(i, j int) bool {
	return h[i] < h[j]
}

func (h IntHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

func (h *IntHeap) Push(x interface{}) {
	(*h) = append(*h, x.(int))
}

func (h *IntHeap) Pop() interface{} {
	n := h.Len()
	top := (*h)[n-1]
	*h = (*h)[:n-1]
	return top
}

func readLine(s *bufio.Scanner) string {
	s.Scan()
	return s.Text()
}

func main() {
	s := bufio.NewScanner(os.Stdin)
	p := bufio.NewWriter(os.Stdout)
	var N, median int
	fmt.Sscanf(readLine(s), "%d", &N)
	fmt.Sscanf(readLine(s), "%d", &median)
	fmt.Fprintf(p, "%d\n", median)
	minHeap := &IntMinHeap{
		make(IntHeap, 0, 100000),
	}
	maxHeap := &IntMaxHeap{
		make(IntHeap, 0, 100000),
	}
	for i := 0; i < N-1; i++ {
		var num int
		fmt.Sscanf(readLine(s), "%d", &num)
		if num >= median {
			heap.Push(minHeap, num)
		} else {
			heap.Push(maxHeap, num)
		}

		minLen := minHeap.Len()
		maxLen := maxHeap.Len()
		if minLen-maxLen >= 2 {
			heap.Push(maxHeap, median)
			median = heap.Pop(minHeap).(int)
		} else if maxLen-minLen >= 1 {
			heap.Push(minHeap, median)
			median = heap.Pop(maxHeap).(int)
		}
		fmt.Fprintf(p, "%d\n", median)
	}
	p.Flush()
}
