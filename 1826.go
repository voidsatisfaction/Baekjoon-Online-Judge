package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"os"
	"sort"
)

type stations []station

type station struct {
	d int
	p int
}

func newStation(d, p int) station {
	return station{d, p}
}

type byDist []station

func (bd byDist) Less(i, j int) bool {
	return bd[i].d < bd[j].d
}

func (bd byDist) Len() int {
	return len(bd)
}

func (bd byDist) Swap(i, j int) {
	bd[i], bd[j] = bd[j], bd[i]
}

type maxHeap []int

func (mh maxHeap) Less(i, j int) bool {
	return mh[j] < mh[i]
}

func (mh maxHeap) Len() int {
	return len(mh)
}

func (mh maxHeap) Swap(i, j int) {
	mh[i], mh[j] = mh[j], mh[i]
}

func (mh *maxHeap) Push(x interface{}) {
	*mh = append(*mh, x.(int))
}

func (mh *maxHeap) Pop() interface{} {
	old := *mh
	n := len(*mh)
	temp := old[n-1]
	*mh = (*mh)[:n-1]
	return temp
}

func readLine(s *bufio.Scanner) string {
	s.Scan()
	return s.Text()
}

func main() {
	s := bufio.NewScanner(os.Stdin)
	var N, cnt, L, P int
	fmt.Sscanf(readLine(s), "%d", &N)
	sts := make(stations, N+2)
	for i := 1; i <= N; i++ {
		var a, b int
		fmt.Sscanf(readLine(s), "%d %d", &a, &b)
		sts[i] = newStation(a, b)
	}
	fmt.Sscanf(readLine(s), "%d %d", &L, &P)
	sts[0] = newStation(0, P)
	sts[N+1] = newStation(L, 0)

	sort.Sort(byDist(sts))

	maxHeap := &maxHeap{}
	heap.Init(maxHeap)

	for i := 1; i <= N+1; i++ {
		currentStation := sts[i]
		if currentStation.d <= P {
			heap.Push(maxHeap, currentStation.p)
		} else {
			for P < currentStation.d {
				if len(*maxHeap) == 0 && P < currentStation.d {
					fmt.Printf("%d\n", -1)
					return
				}
				P += heap.Pop(maxHeap).(int)
				cnt++
			}
			heap.Push(maxHeap, currentStation.p)
		}
	}

	fmt.Printf("%d\n", cnt)
}
