package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func isPossibleLength(l, C int, cut []int) bool {
	cnt, diff := 0, 0
	for i := 1; i < len(cut); i++ {
		diff += cut[i] - cut[i-1]
		if diff > l {
			diff = cut[i] - cut[i-1]
			cnt++
			if diff > l || cnt > C {
				return false
			}
		}
	}
	return true
}

func longestShort(low, high, C int, cut []int) int {
	l := high
	for low <= high {
		mid := (low + high) / 2

		if isPossibleLength(mid, C, cut) {
			l = mid
			high = mid - 1
		} else {
			low = mid + 1
		}
	}
	return l
}

func firstIndex(low, high, C, l int, cut []int) int {
	cnt, diff, index := 0, 0, 0
	for i := len(cut) - 1; i >= 2; i-- {
		diff += cut[i] - cut[i-1]
		if diff > l {
			cnt++
			diff = cut[i] - cut[i-1]
			index = i
			if cnt == C {
				break
			}
		}
	}

	if cnt < C {
		return 1
	}

	return index
}

func main() {
	r := bufio.NewReader(os.Stdin)
	var L, K, C int
	fmt.Scanf("%d %d %d", &L, &K, &C)

	input, _ := r.ReadString('\n')
	inputSlice := strings.Split(strings.TrimSpace(input), " ")
	cut := make([]int, len(inputSlice)+2)
	for i, v := range inputSlice {
		n, _ := strconv.Atoi(v)
		cut[i+1] = n
	}
	cut[0] = 0
	cut[K+1] = L

	sort.Ints(cut)

	l := longestShort(0, L, C, cut)
	index := firstIndex(0, L, C, l, cut)

	fmt.Printf("%d %d\n", l, cut[index])
}
