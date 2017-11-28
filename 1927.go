package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type minHeap []int

func (mh *minHeap) swap(i, j int) {
	(*mh)[i], (*mh)[j] = (*mh)[j], (*mh)[i]
}

func (mh *minHeap) insert(n int) {
	l := len(*mh)
	(*mh) = append((*mh), n)

	currentIndex := l
	parentIndex := (l - 1) / 2
	for currentIndex > 0 && (*mh)[parentIndex] > (*mh)[currentIndex] {
		mh.swap(currentIndex, parentIndex)
		currentIndex = parentIndex
		parentIndex = (currentIndex - 1) / 2
	}
}

func (mh *minHeap) pop() int {
	l := len(*mh)
	if l == 0 {
		return 0
	}
	temp := (*mh)[0]

	mh.swap(l-1, 0)
	(*mh) = (*mh)[:l-1]

	currentIndex := 0
	leftChildIndex := 1
	rightChildIndex := 2
	l--

	for {
		nextChildIndex := 0
		if leftChildIndex >= l {
			break
		}

		if rightChildIndex >= l {
			nextChildIndex = leftChildIndex
		} else {
			if (*mh)[leftChildIndex] < (*mh)[rightChildIndex] {
				nextChildIndex = leftChildIndex
			} else {
				nextChildIndex = rightChildIndex
			}
		}

		if (*mh)[nextChildIndex] < (*mh)[currentIndex] {
			mh.swap(nextChildIndex, currentIndex)
			currentIndex = nextChildIndex
		} else {
			break
		}
		leftChildIndex = 2*currentIndex + 1
		rightChildIndex = 2*currentIndex + 2
	}

	return temp
}

func (mh *minHeap) top() int {
	if len(*mh) > 0 {
		return (*mh)[0]
	}
	return 0
}

func main() {
	var N int
	s := bufio.NewScanner(os.Stdin)
	fmt.Scanf("%d", &N)
	mh := make(minHeap, 0, N)
	for i := 0; i < N; i++ {
		s.Scan()
		x, err := strconv.Atoi(s.Text())
		if err != nil {
			fmt.Printf("%+v", err)
			return
		}
		if x > 0 {
			mh.insert(x)
		} else {
			fmt.Printf("%d\n", mh.pop())
		}
	}
}
