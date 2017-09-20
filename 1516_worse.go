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
	for _, s := range sSlice {
		v, err := strconv.Atoi(s)
		if err != nil {
			return nil, err
		}
		iSlice = append(iSlice, v)
	}
	return iSlice, nil
}

func max(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	maxNum := nums[0]
	for i := 1; i < len(nums); i++ {
		if nums[i] > maxNum {
			maxNum = nums[i]
		}
	}
	return maxNum
}

func sliceMap(nums []int, f func(x int) int) []int {
	mapped := make([]int, len(nums))

	for i := 0; i < len(nums); i++ {
		mapped[i] = f(nums[i])
	}
	return mapped
}

func main() {
	s := bufio.NewScanner(os.Stdin)
	p := bufio.NewWriter(os.Stdout)
	var N int
	fmt.Scanf("%d", &N)

	inDegree := make([]int, N+1)
	parentAdjList := make([][]int, N+1)
	childrenAdjList := make([][]int, N+1)
	buildTime := make([]int, N+1)
	totalBuildTime := make([]int, N+1)
	queue := Queue{0, nil, nil}

	for i := 1; i < N+1; i++ {
		s.Scan()
		input, _ := stringSliceToInt(strings.Split(s.Text(), " "))
		buildTime[i] = input[0]
		for j := 1; input[j] != -1; j++ {
			inDegree[i]++
			parentAdjList[i] = append(parentAdjList[i], input[j])
			childrenAdjList[input[j]] = append(childrenAdjList[input[j]], i)
		}
	}

	for i := 1; i < N+1; i++ {
		if inDegree[i] == 0 {
			queue.push(i)
		}
	}

	for !queue.empty() {
		x := queue.pop()
		for _, node := range childrenAdjList[x] {
			inDegree[node]--
			if inDegree[node] == 0 {
				queue.push(node)
			}
		}

		temp := sliceMap(parentAdjList[x], func(node int) int {
			return totalBuildTime[node]
		})
		totalBuildTime[x] = buildTime[x] + max(temp)
	}

	for i := 1; i < N+1; i++ {
		fmt.Fprintf(p, "%d\n", totalBuildTime[i])
	}
	p.Flush()
}
