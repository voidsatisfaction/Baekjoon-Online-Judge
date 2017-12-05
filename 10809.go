package main

import (
	"bufio"
	"fmt"
	"os"
)

const (
	asciiDiff    = 97
	alphabetNums = 26
)

func main() {
	s := bufio.NewScanner(os.Stdin)
	p := bufio.NewWriter(os.Stdout)

	stringSlice := make([]int, alphabetNums)
	for i := 0; i < alphabetNums; i++ {
		stringSlice[i] = -1
	}

	var word string
	s.Scan()
	fmt.Sscanf(s.Text(), "%s", &word)

	for i, v := range word {
		index := v - asciiDiff
		if stringSlice[index] == -1 {
			stringSlice[index] = i
		}
	}

	for _, v := range stringSlice {
		fmt.Fprintf(p, "%d ", v)
	}
	p.Flush()
}
