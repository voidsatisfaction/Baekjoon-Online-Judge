package main

import (
	"bufio"
	"container/list"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type node struct {
	n int
	m int
}

func newNode(n, m int) *node {
	return &node{
		n, m,
	}
}

func (n *node) hashCode() string {
	return fmt.Sprintf("%d:%d", n.n, n.m)
}

func readLine(r *bufio.Reader) string {
	str, _ := r.ReadString('\n')
	return strings.TrimSpace(str)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func bfs(graph [][]int, n, m, N, M int) int {
	maxGraph := make([][]int, N)
	for i := 0; i < N; i++ {
		maxGraph[i] = make([]int, M)
	}

	queue := list.New()
	queue.PushBack(newNode(n, m))
	for queue.Len() > 0 {
		set := make(map[string]bool)
		newQueue := list.New()
		for e := queue.Front(); e != nil; e = e.Next() {
			eNode := e.Value.(*node)
			if _, ok := set[eNode.hashCode()]; ok {
				continue
			}
			set[eNode.hashCode()] = true
			en, em := eNode.n, eNode.m

			if en == 0 && em > 0 {
				maxGraph[en][em] = maxGraph[en][em-1] + graph[en][em]
			} else if en > 0 && em == 0 {
				maxGraph[en][em] = maxGraph[en-1][em] + graph[en][em]
			} else if en > 0 && em > 0 {
				maxGraph[en][em] = max(maxGraph[en-1][em], maxGraph[en][em-1]) + graph[en][em]
			} else {
				maxGraph[en][em] = graph[en][em]
			}

			if en+1 >= N && em+1 >= M {
				continue
			} else if en+1 >= N {
				newQueue.PushBack(newNode(en, em+1))
			} else if em+1 >= M {
				newQueue.PushBack(newNode(en+1, em))
			} else {
				newQueue.PushBack(newNode(en, em+1))
				newQueue.PushBack(newNode(en+1, em))
			}
		}
		queue = newQueue
	}

	return maxGraph[N-1][M-1]
}

func main() {
	r := bufio.NewReader(os.Stdin)
	var N, M int
	fmt.Sscanf(readLine(r), "%d %d", &N, &M)

	graph := make([][]int, N)
	for i := 0; i < N; i++ {
		inputSlice := strings.Split(readLine(r), " ")
		numSlice := make([]int, len(inputSlice))
		for i, cp := range inputSlice {
			n, _ := strconv.Atoi(cp)
			numSlice[i] = n
		}
		graph[i] = numSlice
	}

	ans := bfs(graph, 0, 0, N, M)

	fmt.Printf("%d\n", ans)
}
