package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Node struct {
	nextNode int
	dist     int
}

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

func bfsLongestNode(node int, tree *[][]Node, dist *[]int) int {
	for i := 0; i < len(*dist); i++ {
		(*dist)[i] = 0
	}
	q := Queue{0, nil, nil}
	visited := make([]bool, len(*tree))
	q.push(node)
	visited[node] = true
	for !q.empty() {
		node = q.pop()
		for _, v := range (*tree)[node] {
			if !visited[v.nextNode] {
				q.push(v.nextNode)
				(*dist)[v.nextNode] = (*dist)[node] + v.dist
				visited[v.nextNode] = true
			}
		}
	}
	longestNode := 1
	for i := 2; i < len(*dist); i++ {
		if (*dist)[i] > (*dist)[longestNode] {
			longestNode = i
		}
	}
	return longestNode
}

func main() {
	var V, nodeNum, nextNode, d int
	s := bufio.NewScanner(os.Stdin)
	p := bufio.NewWriter(os.Stdout)
	fmt.Scanf("%d", &V)

	tree := make([][]Node, V+1)
	dist := make([]int, V+1)

	for i := 0; i < V; i++ {
		s.Scan()
		input, _ := sliceAtoi(strings.Split(s.Text(), " "))
		for j, v := range input {
			if v == -1 {
				break
			}
			if j == 0 {
				nodeNum = v
			} else if j%2 == 1 {
				nextNode = v
			} else {
				d = v
				tree[nodeNum] = append(tree[nodeNum], Node{nextNode, d})
			}
		}
	}
	dia1 := bfsLongestNode(1, &tree, &dist)
	dia2 := bfsLongestNode(dia1, &tree, &dist)

	fmt.Fprintf(p, "%d\n", dist[dia2])
	p.Flush()
}
