function Node(val) {
  this.next = null;
  this.val = val;
}

function LinkedList(node) {
  this.head = node;
}

Node.prototype.traverseToConsole = function() {
  current = this;
  while (current) {
    console.log(current.val);
    current = current.next;
  }
};
