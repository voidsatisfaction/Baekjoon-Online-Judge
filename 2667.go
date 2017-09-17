package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

type Queue struct {
	size int
	head *QueueElement
	tail *QueueElement
}

type QueueElement struct {
	value []int
	next  *QueueElement
}

func (q *Queue) push(n []int) {
	if q.size == 0 {
		q.tail = &QueueElement{n, nil}
		q.head = q.tail
	} else {
		e := QueueElement{n, nil}
		q.tail.next = &e
		q.tail = &e
	}
	q.size++
}

func (q *Queue) pop() []int {
	if q.size == 2 {
		temp := q.head
		q.head = temp.next
		q.tail = temp.next
		q.size--
		return temp.value
	} else if q.size == 1 {
		temp := q.head
		q.head = nil
		q.tail = nil
		q.size--
		return temp.value
	} else if q.size > 0 {
		temp := q.head
		q.head = temp.next
		q.size--
		return temp.value
	}
	return []int{}
}

func (q *Queue) empty() bool {
	if q.size > 0 {
		return false
	}
	return true
}

func (q *Queue) front() []int {
	if q.size > 0 {
		e := q.head
		return e.value
	}
	return []int{}
}

func (q *Queue) back() []int {
	if q.size > 0 {
		e := q.tail
		return e.value
	}
	return []int{}
}

func stringSliceToInt(sSlice []string) ([]int, error) {
	iSlice := make([]int, 0, len(sSlice))
	for _, v := range sSlice {
		a, err := strconv.Atoi(v)
		if err != nil {
			return nil, err
		}
		iSlice = append(iSlice, a)
	}
	return iSlice, nil
}

func bfs(box *[][]int, visited *[][]bool, i int, j int) int {
	(*visited)[i][j] = true
	nextQueue := Queue{0, nil, nil}
	nextQueue.push([]int{i, j})
	counts := 1
	for !nextQueue.empty() {
		nextQueueSize := nextQueue.size
		for i := 0; i < nextQueueSize; i++ {
			t := nextQueue.pop()
			row, col := t[0], t[1]
			dx := []int{col, col, col - 1, col + 1}
			dy := []int{row - 1, row + 1, row, row}
			for j := 0; j < 4; j++ {
				if dy[j] >= 0 && dy[j] < N && dx[j] >= 0 && dx[j] < N && (*box)[dy[j]][dx[j]] == 1 && !(*visited)[dy[j]][dx[j]] {
					nextQueue.push([]int{dy[j], dx[j]})
					(*visited)[dy[j]][dx[j]] = true
					counts++
				}
			}
		}
	}
	return counts
}

var N int

func main() {
	s := bufio.NewScanner(os.Stdin)
	fmt.Scanf("%d", &N)

	ans := []int{}
	box := make([][]int, 0, N)
	visited := make([][]bool, N)

	for i := 0; i < N; i++ {
		s.Scan()
		intSlice, _ := stringSliceToInt(strings.Split(s.Text(), ""))
		box = append(box, intSlice)
	}

	for i := 0; i < N; i++ {
		for j := 0; j < N; j++ {
			visited[i] = append(visited[i], false)
		}
	}

	for i := 0; i < N; i++ {
		for j := 0; j < N; j++ {
			if box[i][j] == 1 && !visited[i][j] {
				ans = append(ans, bfs(&box, &visited, i, j))
			}
		}
	}
	sortedNums := sort.IntSlice(make([]int, len(ans)))
	copy(sortedNums, ans)
	sort.Sort(sortedNums)
	fmt.Printf("%d\n", len(sortedNums))
	for _, v := range sortedNums {
		fmt.Printf("%d\n", v)
	}
}
