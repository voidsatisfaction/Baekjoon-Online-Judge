package main

import "fmt"

func main() {
	var T, n int
	var cache = []int{1, 1, 2}
	fmt.Scanf("%d", &T)
	for T > 0 {
		fmt.Scanf("%d", &n)
		if len(cache)-1 >= n {
			fmt.Printf("%d\n", cache[n])
		} else {
			l := len(cache) - 1
			for l < n {
				cache = append(cache, cache[l]+cache[l-1]+cache[l-2])
				l++
			}
			fmt.Printf("%d\n", cache[n])
		}
		T--
	}
}
