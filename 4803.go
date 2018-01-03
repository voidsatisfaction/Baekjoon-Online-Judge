package main

import (
	"bufio"
	"fmt"
	"os"
)

func noTreeText() string {
	return "No trees."
}

func nTreeText(n int) string {
	return fmt.Sprintf("A forest of %d trees.", n)
}

func oneTreeText() string {
	return "There is one tree."
}

func readLine(s *bufio.Scanner) string {
	s.Scan()
	return s.Text()
}

type UnionFind struct {
	id     []int
	size   []int
	isTree []bool
}

func NewUnionFind(n int) *UnionFind {
	id := make([]int, n+1)
	size := make([]int, n+1)
	isTree := make([]bool, n+1)

	for i := 0; i <= n; i++ {
		id[i] = i
		size[i] = 1
		isTree[i] = true
	}

	return &UnionFind{
		id:     id,
		size:   size,
		isTree: isTree,
	}
}

func (uf *UnionFind) root(x int) int {
	for uf.id[x] != x {
		x = uf.id[x]
	}
	return x
}

func (uf *UnionFind) Union(i, j int) {
	rootI, rootJ := uf.root(i), uf.root(j)
	if uf.size[rootI] >= uf.size[rootJ] {
		uf.id[rootJ] = rootI
		uf.size[rootI] += uf.size[rootJ]
	} else {
		uf.id[rootI] = rootJ
		uf.size[rootJ] += uf.size[rootI]
	}
}

func (uf *UnionFind) Find(i, j int) bool {
	rootI, rootJ := uf.root(i), uf.root(j)
	uf.id[i] = rootI
	uf.id[j] = rootJ
	return rootI == rootJ
}

func main() {
	s := bufio.NewScanner(os.Stdin)
	p := bufio.NewWriter(os.Stdout)

	t := 1
	for {
		var n, m int
		fmt.Sscanf(readLine(s), "%d %d", &n, &m)
		if n == 0 && m == 0 {
			break
		}

		uf := NewUnionFind(n)

		for i := 0; i < m; i++ {
			var a, b int
			fmt.Sscanf(readLine(s), "%d %d", &a, &b)
			if uf.Find(a, b) {
				uf.isTree[a] = false
				uf.isTree[b] = false
				uf.isTree[uf.root(a)] = false
				uf.isTree[uf.root(b)] = false
			} else {
				uf.Union(a, b)
			}
		}

		treeNumSet := make(map[int]bool)
		for i := 1; i < len(uf.id); i++ {
			group := uf.root(uf.id[i])
			if uf.isTree[group] {
				treeNumSet[group] = true
			}
		}

		l := len(treeNumSet)
		switch l {
		case 0:
			fmt.Fprintf(p, "Case %d: %s\n", t, noTreeText())
		case 1:
			fmt.Fprintf(p, "Case %d: %s\n", t, oneTreeText())
		default:
			fmt.Fprintf(p, "Case %d: %s\n", t, nTreeText(l))
		}
		t++
	}
	p.Flush()
}
