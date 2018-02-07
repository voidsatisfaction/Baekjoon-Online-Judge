package main

import "fmt"

func main() {
	var N uint64
	fmt.Scanf("%d", &N)
	fmt.Println(N * (N - 1) / 2)
}
