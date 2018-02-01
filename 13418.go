package main

import (
	"bufio"
	"fmt"
	"os"
)

func readLine(s *bufio.Scanner) string {
	s.Scan()
	return s.Text()
}

type UnionFind struct {
	forest []int
	size   []int
}

func newUnionFind(n int) *UnionFind {
	f := make([]int, n)
	s := make([]int, n)
	for i := 0; i < n; i++ {
		f[i] = i
		s[i] = 1
	}
	return &UnionFind{f, s}
}

func (uf *UnionFind) root(i int) int {
	temp := i
	for uf.forest[i] != i {
		i = uf.forest[i]
	}
	uf.forest[temp] = i
	return i
}

func (uf *UnionFind) union(i, j int) {
	rootI, rootJ := uf.root(i), uf.root(j)
	if uf.size[rootI] > uf.size[rootJ] {
		uf.size[rootI] += uf.size[rootJ]
		uf.forest[rootJ] = rootI
	} else {
		uf.size[rootJ] += uf.size[rootI]
		uf.forest[rootI] = rootJ
	}
}

func (uf *UnionFind) find(i, j int) bool {
	rootI, rootJ := uf.root(i), uf.root(j)
	return rootI == rootJ
}

func main() {
	s := bufio.NewScanner(os.Stdin)
	var N, M int
	fmt.Sscanf(readLine(s), "%d %d", &N, &M)
	var bad, good int
	ufUp := newUnionFind(N + 1)
	ufDown := newUnionFind(N + 1)
	for i := 0; i < M+1; i++ {
		var A, B, C int
		fmt.Sscanf(readLine(s), "%d %d %d", &A, &B, &C)

		if C == 1 { // down
			if ufDown.find(A, B) {
				continue
			}
			ufDown.union(A, B)
		} else { // up
			if ufUp.find(A, B) {
				continue
			}
			ufUp.union(A, B)
			bad++
		}
	}

	set := make(map[int]bool)
	for _, downNode := range ufDown.forest {
		root := ufDown.root(downNode)
		if _, ok := set[root]; !ok {
			set[root] = true
			good++
		}
	}
	good--

	fmt.Printf("%d\n", bad*bad-good*good)
}
