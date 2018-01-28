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

type bySt []*line

func (bs bySt) Less(i, j int) bool {
	return bs[i].st < bs[j].st
}

func (bs bySt) Len() int {
	return len(bs)
}

func (bs bySt) Swap(i, j int) {
	bs[i], bs[j] = bs[j], bs[i]
}

type line struct {
	st int
	ed int
}

func newLine(st, ed int) *line {
	return &line{st, ed}
}

func main() {
	s := bufio.NewScanner(os.Stdin)
	var N int
	fmt.Sscanf(readLine(s), "%d", &N)

	lines := make([]*line, 0, N)
	for i := 0; i < N; i++ {
		var st, ed int
		fmt.Sscanf(readLine(s), "%d %d", &st, &ed)
		lines = append(lines, newLine(st, ed))
	}
	sort.Sort(bySt(lines))

	ss, ee, sum := -1000000001, -1000000001, 0
	for _, line := range lines {
		st, ed := line.st, line.ed
		if ee < st {
			sum = sum + ee - ss
			ss, ee = st, ed
			continue
		}

		if ed > ee {
			ee = ed
		}
	}
	sum = sum + ee - ss

	fmt.Printf("%d\n", sum)
}
