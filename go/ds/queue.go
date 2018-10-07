package ds

import (
	"fmt"
	"strings"
)

var (
	// ErrFullCapacity is returned when the user tries to enqueue element to full queue.
	ErrFullCapacity = fmt.Errorf("queue is full")

	// ErrDequeueFromEmptyQueue is returned when user tries to dequeue from empty queue.
	ErrDequeueFromEmptyQueue = fmt.Errorf("cannot dequeue element from empty queue")
)

// QueueElement defines the element of a queue.
// Contains a pointer to the next element and its value.
type QueueElement struct {
	Value int
	Next  *QueueElement
}

// Queue defines the representation of a queue.
type Queue struct {
	Head *QueueElement
	Tail *QueueElement
	Len  int
	Cap  int
}

// NewQueue returns an empty queue set to the capacity passed in.
func NewQueue(cap int) *Queue {
	return &Queue{
		Head: nil,
		Tail: nil,
		Len:  0,
		Cap:  cap,
	}
}

// Enqueue enqueues an element to the queue. Returns ErrFullCapacity if the queue is already full.
func (q *Queue) Enqueue(val int) error {
	if q.Len == q.Cap {
		return ErrFullCapacity
	}
	q.Len++
	queueEl := &QueueElement{
		Next:  nil,
		Value: val,
	}
	if q.Len == 1 {
		q.Head = queueEl
		q.Tail = q.Head
		return nil
	}
	q.Tail.Next = queueEl
	q.Tail = q.Tail.Next
	return nil
}

// Dequeue returns the element dequeued or an error if the queue is already empty.
func (q *Queue) Dequeue() (int, error) {
	if q.Len == 0 {
		return 0, ErrDequeueFromEmptyQueue
	}
	oldHead := q.Head
	q.Head = q.Head.Next
	q.Len--
	return oldHead.Value, nil
}

// String implements the Stringer interface.
func (q *Queue) String() string {
	if q.Len == 0 {
		return "[]"
	}
	strBuilder := strings.Builder{}
	strBuilder.WriteString("[")
	cursor := q.Head
	for cursor.Next != nil {
		strBuilder.WriteString(fmt.Sprintf("%d, ", cursor.Value))
		cursor = cursor.Next
	}
	strBuilder.WriteString(fmt.Sprintf("%d]", cursor.Value))
	return strBuilder.String()
}
