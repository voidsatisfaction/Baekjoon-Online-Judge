package main

import (
	"bufio"
	"container/list"
	"fmt"
	"os"
)

func readLine(s *bufio.Scanner) string {
	s.Scan()
	return s.Text()
}

func bfs(adjList [][]int, start, N int) (int, int, int) {
	dist, nums := -1, 1
	visited := make([]bool, N+1)
	visited[start] = true
	nextNodes := list.New()
	nextNodes.PushBack(start)

	for {
		n := 20001
		newNextNodes := list.New()
		for node := nextNodes.Front(); node != nil; node = node.Next() {
			nodeNum := node.Value.(int)
			if nodeNum < n {
				n = nodeNum
			}

			for _, adjNode := range adjList[nodeNum] {
				if !visited[adjNode] {
					visited[adjNode] = true
					newNextNodes.PushBack(adjNode)
				}
			}
		}

		dist++
		nums = nextNodes.Len()

		if newNextNodes.Len() == 0 {
			return n, dist, nums
		}
		nextNodes = newNextNodes
	}
}

func main() {
	s := bufio.NewScanner(os.Stdin)
	var N, M int
	fmt.Sscanf(readLine(s), "%d %d", &N, &M)
	adjList := make([][]int, N+1)
	for i := 1; i <= N; i++ {
		adjList[i] = make([]int, 0, 20)
	}

	for i := 0; i < M; i++ {
		var a, b int
		fmt.Sscanf(readLine(s), "%d %d", &a, &b)
		adjList[a] = append(adjList[a], b)
		adjList[b] = append(adjList[b], a)
	}

	n, dist, nums := bfs(adjList, 1, N)

	fmt.Printf("%d %d %d\n", n, dist, nums)
}
