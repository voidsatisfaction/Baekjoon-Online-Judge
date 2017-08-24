package main

import (
	"fmt"
)

func main() {
	var n, t, j, k int
	l := 1
	var no bool
	stack := make([]int, 100001)
	ans := make([]string, 200002)

	fmt.Scanf("%d", &n)

	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &t)
		if stack[j] > t {
			no = true
			break
		}
		for t >= l {
			j++
			stack[j] = l
			l++
			ans[k] = "+"
			k++
		}
		j--
		ans[k] = "-"
		k++
		if no {
			break
		}
	}

	if no {
		fmt.printf("NO")
	} else {
		for f := 0; f < k; f++ {
			fmt.printf("%s", ans[f])
		}
	}
	out.Flush()
}
