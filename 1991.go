package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

type Node struct {
	node      string
	leftNode  int
	rightNode int
}

func preorderTraversal(tree []Node, n int) {
	if n == -1 {
		return
	}
	fmt.Printf("%s", tree[n].node)
	preorderTraversal(tree, tree[n].leftNode)
	preorderTraversal(tree, tree[n].rightNode)
}

func inorderTraversal(tree []Node, n int) {
	if n == -1 {
		return
	}
	inorderTraversal(tree, tree[n].leftNode)
	fmt.Printf("%s", tree[n].node)
	inorderTraversal(tree, tree[n].rightNode)
}

func postorderTraversal(tree []Node, n int) {
	if n == -1 {
		return
	}
	postorderTraversal(tree, tree[n].leftNode)
	postorderTraversal(tree, tree[n].rightNode)
	fmt.Printf("%s", tree[n].node)
}

func main() {
	var N int
	s := bufio.NewScanner(os.Stdin)
	fmt.Scanf("%d", &N)

	m := make(map[string]int, N)
	tree := make([]Node, N)
	for i := 0; i < N; i++ {
		s.Scan()
		scannedString := strings.Split(s.Text(), " ")
		node, leftNode, rightNode := scannedString[0], scannedString[1], scannedString[2]
		v, exists := m[node]
		if !exists {
			v = len(m)
		}
		m[node] = v
		tree[v].node = node
		if leftNode == "." {
			tree[v].leftNode = -1
		} else if m[leftNode] == 0 {
			m[leftNode] = len(m)
			tree[v].leftNode = m[leftNode]
		}
		if rightNode == "." {
			tree[v].rightNode = -1
		} else if m[rightNode] == 0 {
			m[rightNode] = len(m)
			tree[v].rightNode = m[rightNode]
		}
	}
	preorderTraversal(tree, 0)
	fmt.Printf("\n")
	inorderTraversal(tree, 0)
	fmt.Printf("\n")
	postorderTraversal(tree, 0)
}
