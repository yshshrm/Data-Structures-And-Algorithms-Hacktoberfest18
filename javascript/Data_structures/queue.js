/**
 * Data Structures with JavaScript :: Queue
 * 
 * A linear data structure.
 * 
 * FIFO (First In First Out) 
 * 
 * Operations of a Queue:
 *   - enqueue: which adds an element to the collection
 *   - dequeue: which removes the first added element that was not yet removed
 * 
 * https://en.wikipedia.org/wiki/Queue_(abstract_data_type)
 */

function Queue() {
  this.items = [];      // Container for storing data
  this.maxsize = 1024;  // Maximum number of elements 
}

/**
 * Add an element to the collection
 */
Queue.prototype.enqueue = function(item) {
  if (this.items.length >= this.maxsize) {
    // overflow error
    return undefined;
  }

  this.items.push(item);
}

/**
 * Remove an element from the collection
 */
Queue.prototype.dequeue = function() {
  if (this.items.length <= 0) {
    // underflow error
    return undefined;
  }

  return this.items.shift();
}

/**
 *  Observes the first element without removing it from the queue
 */
Queue.prototype.peek = function() {
  if (this.items.length == 0) {
    // is empty
    return undefined;
  }

  return this.items[0]
}

/**
 * Returns the number of elements in the queue
 */
Queue.prototype.size = function() {
  return this.items.length;
}

/**
 * Example
 */

var queue = new Queue();

queue.enqueue('a');
console.log(queue.peek());
queue.enqueue('b');
console.log(queue.peek());

console.log(queue.dequeue());
console.log(queue.peek());

console.log(queue.size());
console.log(queue.peek());
