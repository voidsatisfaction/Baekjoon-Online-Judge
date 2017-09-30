package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	s := bufio.NewScanner(os.Stdin)
	p := bufio.NewWriter(os.Stdout)
	s.Scan()
	str := s.Text()
	ans := ""
	for _, runeStr := range str {
		if runeStr < 91 && runeStr > 64 {
			ans += string(runeStr)
		}
	}
	fmt.Fprintf(p, "%s\n", ans)
	p.Flush()
}
