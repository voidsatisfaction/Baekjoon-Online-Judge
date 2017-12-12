package main

import (
	"bufio"
	"fmt"
	"os"
)

type UnionFind struct {
	id   []int
	size []int
}

func (uf *UnionFind) init(n int) {
	id := make([]int, n+1)
	size := make([]int, n+1)
	for i := 1; i <= n; i++ {
		id[i] = i
		size[i] = 1
	}
	uf.id = id
	uf.size = size
}

func (uf *UnionFind) root(i int) int {
	for i != uf.id[i] {
		i = uf.id[i]
	}
	return i
}

func (uf *UnionFind) union(i, j int) {
	rootI := uf.root(i)
	rootJ := uf.root(j)
	if uf.size[rootI] > uf.size[rootJ] {
		uf.id[rootJ] = rootI
		uf.size[rootI] += uf.size[rootJ]
	} else {
		uf.id[rootI] = rootJ
		uf.size[rootJ] += uf.size[rootI]
	}
}

func (uf *UnionFind) find(i, j int) bool {
	// For path compression
	uf.id[i] = uf.root(i)
	uf.id[j] = uf.root(j)
	return uf.id[i] == uf.id[j]
}

func main() {
	s := bufio.NewScanner(os.Stdin)
	p := bufio.NewWriter(os.Stdout)
	var n, m int
	s.Scan()
	fmt.Sscanf(s.Text(), "%d %d", &n, &m)

	uf := &UnionFind{}
	uf.init(n)
	for i := 0; i < m; i++ {
		var t, a, b int
		s.Scan()
		fmt.Sscanf(s.Text(), "%d %d %d", &t, &a, &b)
		switch t {
		case 0:
			uf.union(a, b)
		case 1:
			if uf.find(a, b) {
				fmt.Fprintf(p, "%s\n", "YES")
			} else {
				fmt.Fprintf(p, "%s\n", "NO")
			}
		}
	}
	p.Flush()
}
