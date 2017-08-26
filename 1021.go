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

func (d *Deque) moveLeft() {
	if d.size > 0 {
		d.push_back(d.head.value)
		d.pop_front()
	}
}

func (d *Deque) moveRight() {
	if d.size > 0 {
		d.push_front(d.tail.value)
		d.pop_back()
	}
}

func (d *Deque) getHowManyMoveTo(n int) int {
	var l, r int
	for d.head.value != n {
		d.moveLeft()
		l++
	}
	r = d.size - l
	if l > r {
		return r
	}
	return l
}

func main() {
	var N, M, count int
	s := bufio.NewScanner(os.Stdin)

	fmt.Scanf("%d %d", &N, &M)
	s.Scan()
	place := strings.Split(s.Text(), " ")
	deque := Deque{0, nil, nil}

	for i := 1; i < N+1; i++ {
		deque.push_back(i)
	}

	for _, numStr := range place {
		num, _ := strconv.Atoi(numStr)
		count += deque.getHowManyMoveTo(num)
		deque.pop_front()
	}
	fmt.Printf("%d\n", count)
}
