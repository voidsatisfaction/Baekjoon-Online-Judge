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
	for _, v := range sSlice {
		a, err := strconv.Atoi(v)
		if err != nil {
			return nil, err
		}
		iSlice = append(iSlice, a)
	}
	return iSlice, nil
}

func isAdj(p1 Point, p2 Point) bool {
	radSum := p1.r + p2.r
	dist := (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y)
	return radSum*radSum >= dist
}

type Point struct {
	x int
	y int
	r int
}

func main() {
	s := bufio.NewScanner(os.Stdin)
	var T, N int
	fmt.Scanf("%d", &T)
	for t := 0; t < T; t++ {
		fmt.Scanf("%d", &N)
		adjList := make([][]int, N)
		points := []Point{}

		for n := 0; n < N; n++ {
			s.Scan()
			intSlice, _ := stringSliceToInt(strings.Split(s.Text(), " "))
			x, y, r := intSlice[0], intSlice[1], intSlice[2]
			points = append(points, Point{x, y, r})
		}

		// getAdjList
		for i, p1 := range points {
			for j, p2 := range points {
				if isAdj(p1, p2) {
					adjList[i] = append(adjList[i], j)
					adjList[j] = append(adjList[j], i)
				}
			}
		}

		// bfs
		groups := 0
		queue := Queue{0, nil, nil}
		visited := make([]bool, N)
		for i := 0; i < N; i++ {
			if visited[i] {
				continue
			}
			visited[i] = true
			queue.push(i)
			for !queue.empty() {
				v := queue.pop()
				for _, temp := range adjList[v] {
					if !visited[temp] {
						visited[temp] = true
						queue.push(temp)
					}
				}
			}
			groups++
		}
		fmt.Printf("%d\n", groups)
	}
}
