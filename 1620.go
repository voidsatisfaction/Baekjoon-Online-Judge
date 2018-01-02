package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func readLine(s *bufio.Scanner) string {
	s.Scan()
	return s.Text()
}

func main() {
	s := bufio.NewScanner(os.Stdin)
	p := bufio.NewWriter(os.Stdout)
	var N, M int
	fmt.Sscanf(readLine(s), "%d %d", &N, &M)
	numToWord := make([]string, N+1)
	wordToNum := make(map[string]int)
	for i := 1; i <= N; i++ {
		var word string
		fmt.Sscanf(readLine(s), "%s", &word)
		numToWord[i] = word
		wordToNum[word] = i
	}

	for i := 0; i < M; i++ {
		var query string
		fmt.Sscanf(readLine(s), "%s", &query)
		if '1' <= query[0] && query[0] <= '9' {
			n, _ := strconv.Atoi(query)
			fmt.Fprintf(p, "%s\n", numToWord[n])
		} else {
			fmt.Fprintf(p, "%d\n", wordToNum[query])
		}
	}

	p.Flush()
}
