package ds

import (
	"fmt"
	"strings"
)

var (
	// ErrCapacityFull is returned when the user tries to insert into a stack that reached its capacity.
	ErrCapacityFull = fmt.Errorf("stack capacity was reached")

	// ErrPopEmpty is returned when the user tries to pop from an empty stack.
	ErrPopEmpty = fmt.Errorf("cannot pop from empty stack")
)

// StackElement defines how the stack element is represented.
type StackElement struct {
	Value int
	Next  *StackElement
	Prev  *StackElement
}

// Stack defines how the stack is represented.
type Stack struct {
	Head *StackElement
	Len  int
	Cap  int
}

// NewStack returns a pointer to a new stack with a specified capacity.
func NewStack(cap int) *Stack {
	return &Stack{
		Head: nil,
		Len:  0,
		Cap:  cap,
	}
}

// Push inserts a new value into the stack.
func (s *Stack) Push(val int) error {
	if s.Len == s.Cap {
		return ErrCapacityFull
	}
	s.Len++
	stackEl := &StackElement{
		Value: val,
		Next:  nil,
		Prev:  s.Head,
	}
	if s.Head == nil {
		s.Head = stackEl
		return nil
	}
	s.Head.Next = stackEl
	s.Head = stackEl
	return nil
}

// Pop removes an element from the stack and returns it together with an error if the
// stack is already empty.
func (s *Stack) Pop() (int, error) {
	if s.Len == 0 {
		return 0, ErrPopEmpty
	}
	s.Len--
	val := s.Head.Value
	if s.Len == 0 {
		s.Head.Next = nil
		s.Head.Prev = nil
		s.Head = nil
		return val, nil
	}
	s.Head.Prev.Next = nil
	s.Head = s.Head.Prev
	return val, nil
}

// String implements the stringer interface.
func (s *Stack) String() string {
	if s.Len == 0 {
		return "[]"
	}
	strBuilder := strings.Builder{}
	strBuilder.WriteString("[")
	cursor := s.Head
	for cursor.Prev != nil {
		strBuilder.WriteString(fmt.Sprintf("%d --> ", cursor.Value))
		cursor = cursor.Prev
	}
	strBuilder.WriteString(fmt.Sprintf("%d]", cursor.Value))
	return strBuilder.String()
}
