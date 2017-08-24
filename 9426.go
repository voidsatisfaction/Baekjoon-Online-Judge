package main

import (
	"fmt"
	"sort"
)

func getMidVal(nums []int) int {
	var midIndex int
	lenNums := len(nums)
	sortedNums := sort.IntSlice(make([]int, lenNums))
	copy(sortedNums, nums)
	sort.Sort(sortedNums)
	if lenNums%2 == 0 {
		midIndex = lenNums/2 + 1
	} else {
		midIndex = (lenNums - 1) / 2
	}
	return sortedNums[midIndex]
}

func main() {
	var N, K, i, m, s, e, ans int
	fmt.Scanf("%d %d", &N, &K)
	nums := make([]int, K)
	for i < K {
		fmt.Scanf("%d", &nums[i])
		i++
	}
	m = getMidVal(nums)
	for i < N {
		s = nums[0]
		fmt.Scanf("%d", &e)
		if s == m || (s > m && e < m) || (s < m && e > m) {
			m = getMidVal(nums)
		}
		nums = nums[1:]
		nums = append(nums, e)
		ans += m
		i++
	}
	m = getMidVal(nums)
	ans += m
	fmt.Println(ans)
}
