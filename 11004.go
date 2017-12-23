package main

import (
	"bufio"
	"fmt"
	"math/rand"
	"os"
	"strconv"
	"strings"
)

func readLine(r *bufio.Reader) string {
	input, _ := r.ReadString('\n')
	return strings.TrimSpace(input)
}

func shuffle(a []int) {
	for i := 0; i < len(a); i++ {
		r := rand.Intn(i + 1)
		a[r], a[i] = a[i], a[r]
	}
}

func swap(i, j int, a []int) {
	a[i], a[j] = a[j], a[i]
}

func partition(low, high int, a []int) (int, int) {
	pibot, i := a[low], low+1
	lt, gt := low, high
	for i <= gt {
		if a[i] < pibot {
			swap(i, lt, a)
			i++
			lt++
		} else if a[i] > pibot {
			swap(i, gt, a)
			gt--
		} else {
			i++
		}
	}
	return lt, gt
}

func quickSelect(k int, a []int) int {
	shuffle(a)
	low, high := 0, len(a)-1
	for high > low {
		lt, gt := partition(low, high, a)
		if lt > k {
			high = lt - 1
		} else if gt < k {
			low = gt + 1
		} else {
			break
		}
	}
	return a[k]
}

func main() {
	r := bufio.NewReader(os.Stdin)

	var N, K int
	fmt.Sscanf(readLine(r), "%d %d", &N, &K)
	input := strings.Split(readLine(r), " ")
	a := make([]int, len(input))
	for i, v := range input {
		n, _ := strconv.Atoi(v)
		a[i] = n
	}

	ans := quickSelect(K-1, a)
	fmt.Printf("%d\n", ans)
}
