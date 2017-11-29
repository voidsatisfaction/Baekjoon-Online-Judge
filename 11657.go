package main

import (
	"bufio"
	"fmt"
	"os"
)

type node struct {
	num  int
	dist int
}

func main() {
	const INF = 987654321
	var N, M, A, B, C int
	s := bufio.NewScanner(os.Stdin)
	p := bufio.NewWriter(os.Stdout)
	fmt.Scanf("%d %d", &N, &M)

	adjList := make([][]node, N+1)
	graph := make([]int, N+1)
	for i := range adjList {
		adjList[i] = make([]node, 0, N+1)
		if i > 1 {
			graph[i] = INF
		}
	}
	for i := 0; i < M; i++ {
		s.Scan()
		fmt.Sscanf(s.Text(), "%d %d %d", &A, &B, &C)
		n := node{
			num:  B,
			dist: C,
		}
		adjList[A] = append(adjList[A], n)
	}

	infiniteLoop := false
	for i := 0; i < N; i++ {
		for j := 1; j <= N; j++ {
			for _, node := range adjList[j] {
				currentNode := j
				adjNode := node.num
				adjDist := node.dist
				if graph[currentNode] != INF {
					if graph[adjNode] > graph[currentNode]+adjDist {
						if i == N-1 {
							infiniteLoop = true
							break
						}
						graph[adjNode] = graph[currentNode] + adjDist
					}
				}
			}
		}
	}

	if infiniteLoop {
		fmt.Fprintf(p, "%d\n", -1)
	} else {
		for i, v := range graph {
			if i > 1 {
				if v == INF {
					v = -1
				}
				fmt.Fprintf(p, "%d\n", v)
			}
		}
	}
	p.Flush()
}
