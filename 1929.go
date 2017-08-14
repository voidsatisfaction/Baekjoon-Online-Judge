package main

import (
	"fmt"
	"math"
)

func filter(array []int, fn func(int) bool) []int {
	result := make([]int, 0)
	for _, e := range array {
		if fn(e) {
			result = append(result, e)
		}
	}
	return result
}

func main() {
	var M, N int
	var primes []int
	fmt.Scanf("%d %d", &M, &N)
	nums := make([]int, N-1)

	if N == 1 {
		return
	}

	for i := 2; i < N+1; i++ {
		nums[i-2] = i
	}

	for float64(nums[0]) <= math.Sqrt(float64(N)) {
		primes = append(primes, nums[0])
		nums = filter(nums, func(n int) bool {
			return n%nums[0] != 0
		})
	}

	for _, n := range nums {
		primes = append(primes, n)
	}

	for _, prime := range primes {
		if prime >= M {
			fmt.Println(prime)
		}
	}
}
