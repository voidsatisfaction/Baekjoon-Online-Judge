package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	r := bufio.NewReader(os.Stdin)
	var N int
	fmt.Scanf("%d", &N)
	input, _ := r.ReadString('\n')
	inputSlice := strings.Split(strings.TrimSpace(input), " ")
	a := make([]int, 0, len(inputSlice))
	for _, str := range inputSlice {
		n, _ := strconv.Atoi(str)
		a = append(a, n)
	}
	twoSumA := make([]bool, 400001)
	ans := 0
	for i := 0; i < N; i++ {
		target := a[i]
		for j := 0; j < i; j++ {
			if twoSumA[target-a[j]+200000] {
				ans++
				break
			}
		}

		for j := 0; j <= i; j++ {
			twoSumA[target+a[j]+200000] = true
		}
	}
	fmt.Printf("%d\n", ans)
}
