package main

import (
	"fmt"
	"reflect"
)

func checkGood(level, i int, seq []int) bool {
	for l := 1; l <= level/2; l++ {
		right := seq[(level - l):level]
		left := seq[(level - 2*l):(level - l)]
		if reflect.DeepEqual(left, right) {
			return false
		}
	}
	return true
}

func backTrack(level, N int, stop *bool, seq []int) {
	if level == N {
		(*stop) = true
		return
	}

	level++
	for i := 1; i <= 3; i++ {
		seq[level-1] = i
		if checkGood(level, i, seq) {
			backTrack(level, N, stop, seq)
		}
		if (*stop) == true {
			return
		}
		seq[level-1] = 0
	}
}

func main() {
	var N int
	fmt.Scanf("%d", &N)

	seq := make([]int, N)
	stop := false
	backTrack(0, N, &stop, seq)

	for i := 0; i < N; i++ {
		fmt.Printf("%d", seq[i])
	}
}
