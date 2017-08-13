package main

import "fmt"

func main() {
	var N, x, y int
	fmt.Scanf("%d", &N)
	ok := false
	for x = 0; 3*x <= N; x++ {
		if (N-3*x)%5 == 0 {
			y = (N - 3*x) / 5
			ok = true
			break
		}
	}
	if ok {
		fmt.Println(x + y)
	} else {
		fmt.Println(-1)
	}
}
