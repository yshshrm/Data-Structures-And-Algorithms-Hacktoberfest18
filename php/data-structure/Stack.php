<?php
/**
 * Data Structure: Stack
 * Property: Last-In-First-Out
 * Methods: Size, Push, Pop, Top, Traverse
 */

class Stack {

    // Member Variables
    private $size = 0;
    private $list = [];

    function __construct($list = [])
    {
        if (is_array($list) && count($list) > 0) {
            $this->list = $list;
            $this->size = count($list);
        }
    }

    // Returns Size of The Stack
    public function size()
    {
        return $this->size;
    }

    // Pushes new Element to Stack
    public function push($value = null)
    {
        if ($value != null) {
            $this->list[] = $value;
            $this->size++;
            return 1;
        }
        return 0;
    }

    // Pops last Element from Stack
    public function pop()
    {
        if ($this->size > 0) {
            $this->size--;
            return array_pop($this->list);
        }
        return null;
    }

    // Return Top Element of Stack
    public function top()
    {
        if ($this->size > 0) {
            return $this->list[$this->size - 1];
        }
        return null;
    }

    // Traverse all Elements in Stack
    public function traverse(callable $callback)
    {
        if ($this->size > 0) {
            return array_map($callback, array_reverse($this->list));
        }
        return [];
    }
}

/**
 * Test Suite
 */
$test_stack = new Stack();

$test_stack->push(5);
$test_stack->push("Hello");
$test_stack->push("World");
$test_stack->push(8);

echo $test_stack->pop();
echo $test_stack->top();

$test_stack->traverse(function($el) {
    echo $el;
});

?>
