package main

import (
	"bufio"
	"fmt"
	"os"
)

func swap(nums []int, i, j int) {
	nums[i], nums[j] = nums[j], nums[i]
}

func up(nums []int, i int) {
	for {
		if i == 0 {
			break
		}

		p := (i - 1) / 2
		if nums[p] > nums[i] {
			break
		}
		swap(nums, i, p)
		i = p
	}
}

func main() {
	p := bufio.NewWriter(os.Stdout)
	var n int
	fmt.Scanf("%d", &n)
	nums := make([]int, 0, n)
	if n == 1 {
		nums = append(nums, 1)
	} else if n == 2 {
		nums = append(nums, 2)
		nums = append(nums, 1)
	} else {
		nums = append(nums, 2)
		nums = append(nums, 1)
		i := 3
		for i <= n {
			nums = append(nums, i)
			swap(nums, i-1, i-2)
			up(nums, i-2)
			i++
		}
	}

	for _, v := range nums {
		fmt.Fprintf(p, "%d ", v)
	}
	p.Flush()
}
