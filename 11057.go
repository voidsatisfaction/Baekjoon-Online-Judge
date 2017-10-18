package main

import "fmt"

func main() {
	var N, ans int
	fmt.Scanf("%d", &N)
	numEndWith := make([]int, 10)
	for i := 0; i < 10; i++ {
		numEndWith[i] = 1
	}

	for ; N > 1; N-- {
		nextNumEndWith := make([]int, 10)
		for i := 0; i < 10; i++ {
			for j := 0; j <= i; j++ {
				nextNumEndWith[i] += numEndWith[j]
			}
			nextNumEndWith[i] %= 10007
		}
		numEndWith = nextNumEndWith
	}

	for _, v := range numEndWith {
		ans += v
	}
	fmt.Printf("%d\n", (ans % 10007))
}
