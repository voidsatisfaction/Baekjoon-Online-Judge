package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	p := bufio.NewWriter(os.Stdout)
	s := bufio.NewScanner(os.Stdin)
	var N, M int
	s.Scan()
	fmt.Sscanf(s.Text(), "%d %d", &N, &M)

	type empty struct{}
	notHeared := make(map[string]empty)
	notHearedAndSeen := make([]string, 0, 500001)

	for i := 0; i < N; i++ {
		s.Scan()
		word := s.Text()
		notHeared[word] = empty{}
	}

	for i := 0; i < M; i++ {
		s.Scan()
		word := s.Text()
		if _, ok := notHeared[word]; ok {
			notHearedAndSeen = append(notHearedAndSeen, word)
		}
	}

	sort.Strings(notHearedAndSeen)

	fmt.Fprintf(p, "%d\n", len(notHearedAndSeen))
	for _, word := range notHearedAndSeen {
		fmt.Fprintf(p, "%s\n", word)
	}
	p.Flush()
}
