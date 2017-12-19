package main

import (
	"bufio"
	"fmt"
	"os"
)

type Student struct {
	tall int
	nums int
}

func newStudent(tall int) *Student {
	return &Student{
		tall: tall,
		nums: 1,
	}
}

type Stack struct {
	top  int
	data []*Student
}

func newStack(size int) *Stack {
	data := make([]*Student, size)
	return &Stack{
		top:  -1,
		data: data,
	}
}

func (s *Stack) topStudent() *Student {
	return s.data[s.top]
}

func (s *Stack) size() int {
	return s.top + 1
}

func (s *Stack) push(st *Student) {
	s.top++
	s.data[s.top] = st
}

func (s *Stack) pop() *Student {
	if s.top != -1 {
		temp := s.data[s.top]
		s.top--
		return temp
	}
	return nil
}

func main() {
	s := bufio.NewScanner(os.Stdin)
	var N int
	s.Scan()
	fmt.Sscanf(s.Text(), "%d", &N)
	ans := 0
	stack := newStack(N)
	for i := 0; i < N; i++ {
		var n int
		s.Scan()
		fmt.Sscanf(s.Text(), "%d", &n)
		if stack.size() == 0 {
			stack.push(newStudent(n))
			continue
		}
		for stack.size() != 0 && n > stack.topStudent().tall {
			top := stack.pop()
			ans += top.nums
		}
		if stack.size() > 0 && n == stack.topStudent().tall {
			topStudent := stack.topStudent()
			ans += topStudent.nums
			topStudent.nums++
			if stack.size() > 1 {
				ans++
			}
			continue
		}
		if stack.size() > 0 {
			ans++
		}
		stack.push(newStudent(n))
	}
	fmt.Printf("%d\n", ans)
}
