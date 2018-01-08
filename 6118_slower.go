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

func bfs(adjList []*list.List, start, N int) (int, int, int) {
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

			for adjNode := adjList[nodeNum].Front(); adjNode != nil; adjNode = adjNode.Next() {
				adjNodeNum := adjNode.Value.(int)
				if !visited[adjNodeNum] {
					visited[adjNodeNum] = true
					newNextNodes.PushBack(adjNodeNum)
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
	adjList := make([]*list.List, N+1)
	for i := 1; i <= N; i++ {
		adjList[i] = list.New()
	}

	for i := 0; i < M; i++ {
		var a, b int
		fmt.Sscanf(readLine(s), "%d %d", &a, &b)
		adjList[a].PushBack(b)
		adjList[b].PushBack(a)
	}

	n, dist, nums := bfs(adjList, 1, N)

	fmt.Printf("%d %d %d\n", n, dist, nums)
}
