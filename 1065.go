package main

import (
	"fmt"
)

func isHan(num int) bool {
	if num < 100 {
		return true
	}

	a := num % 10
	num /= 10
	b := num % 10
	num /= 10
	d := b - a
	for num > 0 {
		a = b
		b = num % 10
		if b-a != d {
			return false
		}
		num /= 10
	}
	return true
}

func main() {
	var N int
	fmt.Scanf("%d", &N)

	if N < 100 {
		fmt.Printf("%d\n", N)
		return
	}

	counts := 99
	for i := 100; i <= N; i++ {
		if isHan(i) {
			counts++
		}
	}
	fmt.Printf("%d\n", counts)
}
