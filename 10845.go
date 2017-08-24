package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Queue struct {
	size int
	head *QueueElement
	tail *QueueElement
}

type QueueElement struct {
	value int
	next  *QueueElement
}

func (q *Queue) push(n int) {
	if q.size == 0 {
		q.tail = &QueueElement{n, nil}
		q.head = q.tail
	} else {
		e := QueueElement{n, nil}
		q.tail.next = &e
		q.tail = &e
	}
	q.size++
}

func (q *Queue) pop() int {
	if q.size == 2 {
		temp := q.head
		q.head = temp.next
		q.tail = temp.next
		q.size--
		return temp.value
	} else if q.size == 1 {
		temp := q.head
		q.head = nil
		q.tail = nil
		q.size--
		return temp.value
	} else if q.size > 0 {
		temp := q.head
		q.head = temp.next
		q.size--
		return temp.value
	}
	return -1
}

func (q *Queue) empty() int {
	if q.size > 0 {
		return 0
	}
	return 1
}

func (q *Queue) front() int {
	if q.size > 0 {
		e := q.head
		return e.value
	}
	return -1
}

func (q *Queue) back() int {
	if q.size > 0 {
		e := q.tail
		return e.value
	}
	return -1
}

func main() {
	var N int
	s := bufio.NewScanner(os.Stdin)
	w := bufio.NewWriter(os.Stdout)
	q := Queue{0, nil, nil}

	fmt.Scanf("%d", &N)
	for i := 0; i < N; i++ {
		s.Scan()
		command := s.Text()
		splitedCommand := strings.Split(command, " ")
		commandName := splitedCommand[0]
		switch commandName {
		case "push":
			v, _ := strconv.Atoi(splitedCommand[1])
			q.push(v)
		case "pop":
			fmt.Fprintf(w, "%d\n", q.pop())
		case "size":
			fmt.Fprintf(w, "%d\n", q.size)
		case "empty":
			fmt.Fprintf(w, "%d\n", q.empty())
		case "front":
			fmt.Fprintf(w, "%d\n", q.front())
		case "back":
			fmt.Fprintf(w, "%d\n", q.back())
		}
	}
	w.Flush()
}
