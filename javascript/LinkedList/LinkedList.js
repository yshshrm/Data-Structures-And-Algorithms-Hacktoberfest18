function LinkedList(node) {
  this.head = node;
}

function Node(val) {
  this.next = null;
  this.val = val;
}

Node.prototype.addToEnd = function(val) {
  const end = new Node(val);
  let n = this;
  while (n.next) {
    n = n.next;
  }
  n.next = end;
};
