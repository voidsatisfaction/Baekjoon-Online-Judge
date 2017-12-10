package main

import (
	"bufio"
	"fmt"
	"os"
)

func isPatternMatch(ts, is string) bool {
	if len(ts)-1 > len(is) {
		return false
	}
	// for front code point until *
	ft := 0
	fi := 0
	for ts[ft] != '*' {
		if ts[ft] != is[fi] {
			return false
		}
		ft++
		fi++
	}

	// for back code point until *
	bt := len(ts) - 1
	bi := len(is) - 1
	for ts[bt] != '*' {
		if ts[bt] != is[bi] {
			return false
		}
		bt--
		bi--
	}
	return true
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
