package main

import (
	"fmt"
)

type Node struct {
	leftNode  string
	rightNode string
}

type searchFunc func(f searchFunc, tree map[string]Node, node string) string

func searchFuncGenerator(funcType string) searchFunc {
	f := func(f searchFunc, tree map[string]Node, node string) string {
		if node == "." {
			return ""
		}
		switch funcType {
		case "preorder":
			return node + f(f, tree, tree[node].leftNode) + f(f, tree, tree[node].rightNode)
		case "inorder":
			return f(f, tree, tree[node].leftNode) + node + f(f, tree, tree[node].rightNode)
		case "postorder":
			return f(f, tree, tree[node].leftNode) + f(f, tree, tree[node].rightNode) + node
		}
		return ""
	}
	return f
}

func main() {
	var n int
	m := make(map[string]Node)
	fmt.Scanf("%d", &n)
	for i := 0; i < n; i++ {
		var node, left, right string
		fmt.Scanf("%s %s %s", &node, &left, &right)
		m[node] = Node{left, right}
	}
	preorder := searchFuncGenerator("preorder")
	inorder := searchFuncGenerator("inorder")
	postorder := searchFuncGenerator("postorder")
	fmt.Printf("%s\n", preorder(preorder, m, "A"))
	fmt.Printf("%s\n", inorder(inorder, m, "A"))
	fmt.Printf("%s\n", postorder(postorder, m, "A"))
}
