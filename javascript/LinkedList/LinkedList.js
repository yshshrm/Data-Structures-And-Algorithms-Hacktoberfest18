function LinkedList(node) {
  this.head = node;
}

function Node(val) {
  this.next = null;
  this.val = val;
}

LinkedList.prototype.addToEnd = function(val) {
  const end = new Node(val);
  let n = this.head;
  while (n.next) {
    n = n.next;
  }
  n.next = end;
};

LinkedList.prototype.addToBeginning = function(val) {
	const beginning = new Node(val);
	let temp = this.head;
	this.head = beginning;
	beginning.next = temp;
}

LinkedList.prototype.removeFromEnd = function() {
	let n = this.head;
	let previous = null;
  while (n.next) {
  	previous = n;
    n = n.next;
  }
  previous.next = null;
  return n.val;
}

LinkedList.prototype.removeFromBeginning = function() {
	let n = this.head;
	this.head = this.head.next;
	return n.val;
}