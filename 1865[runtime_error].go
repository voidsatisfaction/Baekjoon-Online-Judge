package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const (
	INF   = 100000000
	MAX_N = 501
)

var T, N, M, W int

type Times []int
type IS_INFINITE bool
type adjNode struct {
	num   int
	times int
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

func bellmanFord(from int, to int, adjList [][]adjNode) (Times, IS_INFINITE) {
	var inf IS_INFINITE = false

	takingTimes := make(Times, MAX_N)
	for i := 0; i < len(takingTimes); i++ {
		takingTimes[i] = INF
	}
	takingTimes[from] = 0

	for i := 1; i < N+1; i++ {
		// 마이너스 루프가 있는지 조사해야함.
		for j := 1; j < N+1; j++ {
			for _, adjNode := range adjList[j] {
				adjNodeNum, adjNodeTimes := adjNode.num, adjNode.times
				if takingTimes[adjNodeNum] > takingTimes[j]+adjNodeTimes {
					takingTimes[adjNodeNum] = takingTimes[j] + adjNodeTimes
					if i == N {
						inf = true
					}
				}
			}
		}
	}

	if inf {
		return make([]int, 1), inf
	}
	return takingTimes, inf
}

func main() {
	fmt.Scanf("%d", &T)
	s := bufio.NewScanner(os.Stdin)
	p := bufio.NewWriter(os.Stdout)
	for t := 0; t < T; t++ {
		fmt.Scanf("%d %d %d", &N, &M, &W)
		adjList := make([][]adjNode, N+1)

		for i := 0; i < M; i++ {
			s.Scan()
			var from, to, times int
			input, _ := stringSliceToInt(strings.Split(s.Text(), " "))
			from, to, times = input[0], input[1], input[2]
			inputNode := adjNode{to, times}
			adjList[from] = append(adjList[from], inputNode)
			adjList[to] = append(adjList[to], inputNode)
		}
		for i := 0; i < W; i++ {
			s.Scan()
			var from, to, times int
			input, _ := stringSliceToInt(strings.Split(s.Text(), " "))
			from, to, times = input[0], input[1], input[2]
			inputNode := adjNode{to, -times}
			adjList[from] = append(adjList[from], inputNode)
		}

		_, inf := bellmanFord(1, 1, adjList)

		if inf {
			fmt.Fprintf(p, "%s\n", "YES")
		} else {
			fmt.Fprintf(p, "%s\n", "NO")
		}
	}
	p.Flush()
}
