package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Stack struct {
	size int
	head *StackElement
}

type StackElement struct {
	value int
	next  *StackElement
}

func (s *Stack) push(n int) {
	e := StackElement{n, s.head}
	s.head = &e
	s.size++
}

func (s *Stack) pop() int {
	if s.size > 0 {
		temp := s.head
		s.head = temp.next
		s.size--
		return temp.value
	}
	return -1
}

func (s *Stack) empty() int {
	if s.size > 0 {
		return 0
	}
	return 1
}

func (s *Stack) top() int {
	if s.size > 0 {
		firstElement := s.head
		return firstElement.value
	}
	return -1
}

func main() {
	var N int
	var command string
	stack := Stack{0, nil}

	s := bufio.NewScanner(os.Stdin)
	w := bufio.NewWriter(os.Stdout)
	fmt.Scanf("%d", &N)

	for i := 0; i < N; i++ {
		s.Scan()
		command = s.Text()
		splitedCommand := strings.Split(command, " ")
		commandName := splitedCommand[0]
		switch commandName {
		case "push":
			v, _ := strconv.Atoi(splitedCommand[1])
			stack.push(v)
		case "pop":
			fmt.Fprintf(w, "%d\n", stack.pop())
		case "size":
			fmt.Fprintf(w, "%d\n", stack.size)
		case "empty":
			fmt.Fprintf(w, "%d\n", stack.empty())
		case "top":
			fmt.Fprintf(w, "%d\n", stack.top())
		}
	}
	w.Flush()
}
