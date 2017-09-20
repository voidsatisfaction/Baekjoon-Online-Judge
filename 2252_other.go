package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Queue struct {
	size int
	head *QueueElement
	tail *QueueElement
}

type QueueElement struct {
	value int
	next  *QueueElement
}

func (q *Queue) push(n int) {
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

func (q *Queue) pop() int {
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
	return -1
}

func (q *Queue) empty() bool {
	if q.size > 0 {
		return false
	}
	return true
}

func (q *Queue) front() int {
	if q.size > 0 {
		e := q.head
		return e.value
	}
	return -1
}

func (q *Queue) back() int {
	if q.size > 0 {
		e := q.tail
		return e.value
	}
	return -1
}

func stringSliceToInt(sSlice []string) ([]int, error) {
	iSlice := make([]int, 0, len(sSlice))
	for _, s := range sSlice {
		v, err := strconv.Atoi(s)
		if err != nil {
			return nil, err
		}
		iSlice = append(iSlice, v)
	}
	return iSlice, nil
}

func main() {
	s := bufio.NewScanner(os.Stdin)
	p := bufio.NewWriter(os.Stdout)
	var N, M int
	fmt.Scanf("%d %d", &N, &M)

	children := make([][]int, N+1)
	inDegree := make([]int, N+1)
	queue := Queue{0, nil, nil}
	ans := make([]int, 0, N)

	for i := 0; i < M; i++ {
		s.Scan()
		input, _ := stringSliceToInt(strings.Split(s.Text(), " "))
		a, b := input[0], input[1]
		children[a] = append(children[a], b)
		inDegree[b]++
	}

	for i, degree := range inDegree {
		if degree == 0 && i > 0 {
			queue.push(i)
		}
	}

	for !queue.empty() {
		x := queue.pop()
		for _, n := range children[x] {
			inDegree[n]--
			if inDegree[n] == 0 {
				queue.push(n)
			}
		}
		ans = append(ans, x)
	}

	for _, v := range ans {
		fmt.Fprintf(p, "%d ", v)
	}

	p.Flush()
}
