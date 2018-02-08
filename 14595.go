package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func readLine(s *bufio.Scanner) string {
	s.Scan()
	return s.Text()
}

type queries []query

type query struct {
	a int
	b int
}

func newQuery(a, b int) query {
	return query{a, b}
}

type byQueryA []query

func (ba byQueryA) Less(i, j int) bool {
	return ba[i].a < ba[j].a
}

func (ba byQueryA) Len() int {
	return len(ba)
}

func (ba byQueryA) Swap(i, j int) {
	ba[i], ba[j] = ba[j], ba[i]
}

func main() {
	s := bufio.NewScanner(os.Stdin)
	var N, M int
	fmt.Sscanf(readLine(s), "%d", &N)
	fmt.Sscanf(readLine(s), "%d", &M)
	qs := make(queries, M)
	for i := 0; i < M; i++ {
		var a, b int
		fmt.Sscanf(readLine(s), "%d %d", &a, &b)
		q := newQuery(a, b)
		qs[i] = q
	}

	sort.Sort(byQueryA(qs))

	b, ans := 0, 0
	for _, q := range qs {
		if q.a > b {
			ans += (q.a - b)
			b = q.b
		} else if q.b > b {
			b = q.b
		}
	}

	if M > 0 {
		ans += (N - b)
	} else {
		ans += N
	}

	fmt.Printf("%d\n", ans)
}
