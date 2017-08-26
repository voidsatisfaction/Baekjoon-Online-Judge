package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Deque struct {
	size int
	head *DequeElement
	tail *DequeElement
}

type DequeElement struct {
	value int
	prev  *DequeElement
	next  *DequeElement
}

func (d *Deque) push_front(n int) {
	if d.size > 0 {
		temp := d.head
		d.head = &DequeElement{n, nil, temp}
	} else {
		d.head = &DequeElement{n, nil, nil}
		d.tail = d.head
	}
	d.size++
}

func (d *Deque) push_back(n int) {
	if d.size > 0 {
		e := DequeElement{n, d.tail, nil}
		d.tail.next = &e
		d.tail = &e
	} else {
		d.tail = &DequeElement{n, d.tail, nil}
		d.head = d.tail
	}
	d.size++
}

func (d *Deque) pop_front() int {
	if d.size > 2 {
		e := d.head
		d.head = e.next
		d.size--
		return e.value
	} else if d.size > 0 {
		e := d.head
		d.head = e.next
		d.tail = e.next
		d.size--
		return e.value
	}
	return -1
}

func (d *Deque) pop_back() int {
	if d.size > 1 {
		e := d.tail
		d.tail = e.prev
		d.size--
		return e.value
	} else if d.size == 1 {
		e := d.tail
		d.head = nil
		d.tail = nil
		d.size--
		return e.value
	}
	return -1
}

func (d *Deque) empty() int {
	if d.size > 0 {
		return 0
	}
	return 1
}

func (d *Deque) front() int {
	if d.size > 0 {
		return d.head.value
	}
	return -1
}

func (d *Deque) back() int {
	if d.size > 0 {
		return d.tail.value
	}
	return -1
}

func main() {
	var N int

	s := bufio.NewScanner(os.Stdin)
	w := bufio.NewWriter(os.Stdout)
	d := Deque{0, nil, nil}
	fmt.Scanf("%d", &N)
	for i := 0; i < N; i++ {
		s.Scan()
		command := s.Text()
		splitedCommand := strings.Split(command, " ")
		commandName := splitedCommand[0]
		switch commandName {
		case "push_front":
			v, _ := strconv.Atoi(splitedCommand[1])
			d.push_front(v)
		case "push_back":
			v, _ := strconv.Atoi(splitedCommand[1])
			d.push_back(v)
		case "pop_front":
			fmt.Fprintf(w, "%d\n", d.pop_front())
		case "pop_back":
			fmt.Fprintf(w, "%d\n", d.pop_back())
		case "size":
			fmt.Fprintf(w, "%d\n", d.size)
		case "empty":
			fmt.Fprintf(w, "%d\n", d.empty())
		case "front":
			fmt.Fprintf(w, "%d\n", d.front())
		case "back":
			fmt.Fprintf(w, "%d\n", d.back())
		}
	}
	w.Flush()
}
