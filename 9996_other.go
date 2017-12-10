package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func isPatternMatch(ts, is string) bool {
	if len(ts)-1 > len(is) {
		return false
	}
	tss := strings.Split(ts, "*")
	frontString := tss[0]
	backString := tss[1]
	return strings.HasPrefix(is, frontString) && strings.HasSuffix(is, backString)
}

func main() {
	s := bufio.NewScanner(os.Stdin)
	p := bufio.NewWriter(os.Stdout)

	var N int
	s.Scan()
	fmt.Sscanf(s.Text(), "%d", &N)
	s.Scan()
	targetString := s.Text()
	for i := 0; i < N; i++ {
		s.Scan()
		inputString := s.Text()
		if isPatternMatch(targetString, inputString) {
			fmt.Fprintf(p, "%s\n", "DA")
		} else {
			fmt.Fprintf(p, "%s\n", "NE")
		}
	}

	p.Flush()
}
