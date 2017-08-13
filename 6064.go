package main

import "fmt"

func gcd(a int, b int) int {
	var high, low int
	if a >= b {
		high, low = a, b
	} else {
		high, low = b, a
	}

	if high%low == 0 {
		return low
	}

	return gcd((high % low), low)
}

func getYear(M int, N int, x int, y int) int {
	var high, low, k, l, year int
	if M >= N {
		high, low, k, l = M, N, x, y
	} else {
		high, low, k, l = N, M, y, x
	}

	if (k-l)%gcd(M, N) != 0 {
		return -1
	}

	yearLimit := M * N / gcd(M, N)

	for i := 0; high*i+k < yearLimit+1; i++ {
		year = high*i + k
		if (year-l)%low == 0 {
			return year
		}
	}
	return -1
}

func main() {
	var T, M, N, x, y int
	fmt.Scanf("%d", &T)
	for i := 0; i < T; i++ {
		fmt.Scanf("%d %d %d %d", &M, &N, &x, &y)
		fmt.Println(getYear(M, N, x, y))
	}
}
