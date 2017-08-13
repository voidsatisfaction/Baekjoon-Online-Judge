package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func filter(strArr []string, fn func(string) bool) []string {
	var result []string
	for _, word := range strArr {
		if fn(word) {
			result = append(result, word)
		}
	}
	return result
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	str, _ := reader.ReadString('\n')

	trimmedString := strings.TrimSpace(str)
	filteredSlice := filter(strings.Split(trimmedString, " "), func(s string) bool {
		return s != ""
	})

	fmt.Println(len(filteredSlice))
}
