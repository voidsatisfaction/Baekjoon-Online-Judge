package main

import (
	"bufio"
	"fmt"
	"os"
)

func readLine(s *bufio.Scanner) string {
	s.Scan()
	return s.Text()
}

func sum(n int) uint64 {
	i := uint64(n)
	return i * (i + 1) / 2
}

func main() {
	s := bufio.NewScanner(os.Stdin)
	p := bufio.NewWriter(os.Stdout)

	sums := make([]uint64, 1000001)
	for i := 1; i <= 1000000; i++ {
		sums[i] = sums[i-1] + sum(i)
	}
	for {
		var n int
		fmt.Sscanf(readLine(s), "%d", &n)
		if n == 0 {
			break
		}
		fmt.Fprintf(p, "%d\n", sums[n])
	}
	p.Flush()
}
