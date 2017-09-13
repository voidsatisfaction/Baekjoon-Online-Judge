package main

import (
	"bufio"
	"fmt"
	"os"
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

func (q *Queue) empty() int {
	if q.size > 0 {
		return 0
	}
	return 1
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

func main() {
	var N, a, b int
	fmt.Scanf("%d", &N)
	s := bufio.NewScanner(os.Stdin)
	o := bufio.NewWriter(os.Stdout)
	candidate := make([][]int, N+1)
	visited := make([]bool, N+1)
	ans := make([]int, N+1)

	for i := 0; i < N-1; i++ {
		s.Scan()
		fmt.Sscanf(s.Text(), "%d %d", &a, &b)
		candidate[a] = append(candidate[a], b)
		candidate[b] = append(candidate[b], a)
	}

	queue := Queue{0, nil, nil}
	queue.push(1)
	visited[1] = true

	for queue.size > 0 {
		x := queue.front()
		queue.pop()
		for _, v := range candidate[x] {
			if !visited[v] {
				queue.push(v)
				ans[v] = x
				visited[v] = true
			}
		}
	}

	for i := 2; i < len(ans); i++ {
		fmt.Fprintln(o, ans[i])
	}
	o.Flush()
}
