package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	s := bufio.NewReader(os.Stdin)
	var N int
	fmt.Scanf("%d", &N)

	nums := make([]int, 0, N+1)
	input, _ := s.ReadString('\n')
	strSlice := strings.Split(strings.TrimSpace(input), " ")
	for _, c := range strSlice {
		n, _ := strconv.Atoi(c)
		nums = append(nums, n)
	}

	sort.Ints(nums)

	for i := 0; i < N; i++ {
		nums[i] -= i
	}

	sort.Ints(nums)

	ans := N + nums[N-1] + 1

	fmt.Printf("%d\n", ans)
}
