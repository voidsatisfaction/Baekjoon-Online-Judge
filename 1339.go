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

func power(n, k int) int {
	v := 1
	for i := 0; i < k; i++ {
		v *= n
	}
	return v
}

type data struct {
	coeff int
	num   int
}

type byCoeff []data

func (ds byCoeff) Less(i, j int) bool {
	return ds[i].coeff > ds[j].coeff
}

func (ds byCoeff) Len() int {
	return len(ds)
}

func (ds byCoeff) Swap(i, j int) {
	ds[i], ds[j] = ds[j], ds[i]
}

func getCoeffMapFrom(word string, coeffMap map[rune]data) {
	l := len(word)
	for i, cp := range word {
		if _, ok := coeffMap[cp]; !ok {
			coeffMap[cp] = data{
				coeff: power(10, l-i-1),
			}
		} else {
			d := coeffMap[cp]
			d.coeff += power(10, l-i-1)
			coeffMap[cp] = d
		}
	}
}

func main() {
	s := bufio.NewScanner(os.Stdin)
	var N int
	fmt.Sscanf(readLine(s), "%d", &N)

	coeffMap := make(map[rune]data)
	for i := 0; i < N; i++ {
		var word string
		fmt.Sscanf(readLine(s), "%s", &word)
		getCoeffMapFrom(word, coeffMap)
	}

	dataSlice := make([]data, 0, len(coeffMap))
	for _, data := range coeffMap {
		dataSlice = append(dataSlice, data)
	}
	sort.Sort(byCoeff(dataSlice))

	ans := 0
	for i, data := range dataSlice {
		ans += (9 - i) * data.coeff
	}

	fmt.Printf("%d\n", ans)
}
