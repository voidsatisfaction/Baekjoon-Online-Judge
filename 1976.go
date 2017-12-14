package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type UnionFind struct {
	Id   []int
	Size []int
}

func newUnionFind(n int) *UnionFind {
	id := make([]int, n+1)
	size := make([]int, n+1)
	for i := 0; i <= n; i++ {
		id[i] = i
	}

	uf := &UnionFind{
		Id:   id,
		Size: size,
	}
	return uf
}

func (uf *UnionFind) Root(n int) int {
	id := uf.Id
	for id[n] != n {
		n = id[n]
	}
	return n
}

func (uf *UnionFind) Union(a, b int) {
	size := uf.Size
	rootA := uf.Root(a)
	rootB := uf.Root(b)
	if size[rootA] > size[rootB] {
		uf.Id[rootB] = rootA
		size[rootA] += size[rootB]
	} else {
		uf.Id[rootA] = rootB
		size[rootB] += size[rootA]
	}
}

func (uf *UnionFind) Find(a, b int) bool {
	uf.Id[a] = uf.Root(a)
	uf.Id[b] = uf.Root(b)
	return uf.Id[a] == uf.Id[b]
}

func main() {
	r := bufio.NewReader(os.Stdin)
	var N, M int
	fmt.Scanf("%d", &N)
	fmt.Scanf("%d", &M)

	uf := newUnionFind(N)
	for i := 0; i < N; i++ {
		input, _ := r.ReadString('\n')
		strSlice := strings.Split(strings.TrimSpace(input), " ")
		for i := 0; i < len(strSlice); i++ {
			if strSlice[i] == "1" {
				n, _ := strconv.Atoi(strSlice[i])
				uf.Union(i+1, n)
			}
		}
	}
	input, _ := r.ReadString('\n')
	strSlice := strings.Split(strings.TrimSpace(input), " ")
	first, _ := strconv.Atoi(strSlice[0])

	ans := "YES"
	root := uf.Root(first)
	for i := 1; i < len(strSlice); i++ {
		n, _ := strconv.Atoi(strSlice[i])
		if root != uf.Root(n) {
			ans = "NO"
			break
		}
	}
	fmt.Printf("%s\n", ans)
}
