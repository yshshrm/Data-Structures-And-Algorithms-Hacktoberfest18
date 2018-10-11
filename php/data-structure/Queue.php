<?php
/**
 * Data Structure: Queue
 * Property: First-In-First-Out
 * Methods: Size, Push, Pop, Top, Traverse
 */

class Queue {

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

    // Returns Size of The Queue
    public function size()
    {
        return $this->size;
    }

    // Pushes new Element to Queue
    public function push($value = null)
    {
        if ($value != null) {
            $this->list[] = $value;
            $this->size++;
            return 1;
        }
        return 0;
    }

    // Pops last Element from Queue
    public function pop()
    {
        if ($this->size > 0) {
            $this->size--;
            return array_shift($this->list);
        }
        return null;
    }

    // Return Top Element of Queue
    public function top()
    {
        if ($this->size > 0) {
            return $this->list[0];
        }
        return null;
    }

    // Traverse all Elements in Queue
    public function traverse(callable $callback)
    {
        if ($this->size > 0) {
            return array_map($callback, $this->list);
        }
        return [];
    }
}

/**
 * Test Suite
 */
$test_Queue = new Queue();

$test_Queue->push(5);
$test_Queue->push("Hello");
$test_Queue->push("World");
$test_Queue->push(8);

echo $test_Queue->pop();
echo $test_Queue->top();

$test_Queue->traverse(function($el) {
    echo $el;
});

?>
