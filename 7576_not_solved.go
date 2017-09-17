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

func main() {
	var M, N, day int
	s := bufio.NewScanner(os.Stdin)
	p := bufio.NewWriter(os.Stdout)
	fmt.Scanf("%d %d", &M, &N)

	box := make([][]int, 0, N)

	for i := 0; i < N; i++ {
		s.Scan()
		intSlice, _ := stringSliceToInt(strings.Split(s.Text(), " "))
		fmt.Println(intSlice)
		box = append(box, intSlice)
	}
	fmt.Println(box)

	nextQueue := Queue{0, nil, nil}

	var remains int
	for i := 0; i < N; i++ {
		for j := 0; j < M; j++ {
			if box[i][j] == 1 {
				nextQueue.push([]int{i, j})
			}
			if box[i][j] == 0 {
				remains++
			}
		}
	}

	for !nextQueue.empty() {
		if remains == 0 {
			break
		}
		nextQueueSize := nextQueue.size
		for i := 0; i < nextQueueSize; i++ {
			t := nextQueue.pop()
			row, col := t[0], t[1]
			if row-1 >= 0 && box[row-1][col] == 0 {
				box[row-1][col] = 1
				nextQueue.push([]int{row - 1, col})
				remains--
			}
			if row+1 < N && box[row+1][col] == 0 {
				box[row+1][col] = 1
				nextQueue.push([]int{row + 1, col})
				remains--
			}
			if col-1 >= 0 && box[row][col-1] == 0 {
				box[row][col-1] = 1
				nextQueue.push([]int{row, col - 1})
				remains--
			}
			if col+1 < M && box[row][col+1] == 0 {
				box[row][col+1] = 1
				nextQueue.push([]int{row, col + 1})
				remains--
			}
		}
		day++
	}

	if remains > 0 {
		fmt.Fprintf(p, "%d\n", -1)
	} else {
		fmt.Fprintf(p, "%d\n", day)
	}
	p.Flush()
}
