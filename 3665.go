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

func sliceAtoi(sa []string) ([]int, error) {
	si := make([]int, 0, len(sa))
	for _, a := range sa {
		i, err := strconv.Atoi(a)
		if err != nil {
			return si, err
		}
		si = append(si, i)
	}
	return si, nil
}

func main() {
	s := bufio.NewScanner(os.Stdin)
	p := bufio.NewWriter(os.Stdout)
	var T, N, M int
	fmt.Scanf("%d", &T)
	for a := 0; a < T; a++ {
		fmt.Scanf("%d", &N)
		s.Scan()
		input, _ := sliceAtoi(strings.Split(s.Text(), " "))

		adjMatrix := make([][]bool, N+1)
		for i := 0; i < N+1; i++ {
			for j := 0; j < N+1; j++ {
				adjMatrix[i] = append(adjMatrix[i], false)
			}
		}
		inDegree := make([]int, N+1)

		for i := 0; i < N; i++ {
			for j := i + 1; j < N; j++ {
				adjMatrix[input[i]][input[j]] = true
				inDegree[input[j]]++
			}
		}
		fmt.Scanf("%d", &M)
		for b := 0; b < M; b++ {
			s.Scan()
			input, _ = sliceAtoi(strings.Split(s.Text(), " "))
			m, n := input[0], input[1]
			if adjMatrix[m][n] {
				adjMatrix[m][n] = false
				adjMatrix[n][m] = true
				inDegree[m]++
				inDegree[n]--
			} else {
				adjMatrix[n][m] = false
				adjMatrix[m][n] = true
				inDegree[n]++
				inDegree[m]--
			}
		}

		queue := Queue{0, nil, nil}
		ans := make([]int, 0, N)

		for i := 1; i < N+1; i++ {
			if inDegree[i] == 0 {
				queue.push(i)
				ans = append(ans, i)
			}
		}

		for !queue.empty() {
			if queue.size >= 2 {
				fmt.Fprintf(p, "%s", "?")
				break
			}
			x := queue.pop()
			for i := 1; i < N+1; i++ {
				if adjMatrix[x][i] {
					inDegree[i]--
					if inDegree[i] == 0 {
						queue.push(i)
						ans = append(ans, i)
					}
				}
			}
		}

		impossible := false
		for _, degree := range inDegree {
			if degree != 0 {
				impossible = true
				fmt.Fprintf(p, "%s", "IMPOSSIBLE")
				break
			}
		}

		if !impossible {
			for i := 0; i < N; i++ {
				fmt.Fprintf(p, "%d ", ans[i])
			}
		}
		fmt.Fprintf(p, "\n")
	}
	p.Flush()
}
