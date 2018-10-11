class Node {
  constructor(value) {
    this.value = value;
    this.next = null;
    this.prev = null;
  }
}

class LinkedList {
  constructor(name) {
    this.name = name;
    this.head = null;
    this.tail = null;
  }

  addToHead(nodeValue) {
    const oldHead = this.head;
    const node = new Node(nodeValue);

    if (oldHead) {
      this.head = node;
      this.head.next = oldHead;
      this.head.next.prev = node;

    } else {
      this.head = this.tail = node;
    };

  };
  
  addToTail(nodeValue) {
    const node = new Node(nodeValue);
    const oldTail = this.tail;
    
    if(!this.head && !this.tail) {
      this.head = this.tail = node;
    };

    if(oldTail) {
      this.tail = node;
      this.tail.prev = oldTail;
      this.tail.prev.next = node;
      return this.tail;
    };
  };

  // adds a new node in the middle of the linked list
  addWhereN(nodeValue, n) {
    let currentNode = this.head;
    const node = new Node(nodeValue);

    for(let i=1; i < n; i++) {
      if(!currentNode) return console.log(`addWhereN: There aren't that many nodes in this list yet...`);
      currentNode = currentNode.next;
    };

    // 1. change prev node's next to new node
    currentNode.prev.next = node;
    
    // 2. new node's prev to prev node and new node's next to the next node (AKA the current node prior to shift)
    node.prev = currentNode.prev;
    node.next = currentNode;
    
    currentNode = node;
    // 3. change next node's prev to new node
    currentNode.next.prev = node;
    return currentNode;
  };

  removeHead() {
    if(this.head) {
      this.head = this.head.next ? this.head.next : null;
      this.head.prev = null;
      return this.head;

    } else {
      console.log(`There is no head node.`);
    };
  };

  removeTail() {
    if(this.tail) {
      this.tail.prev.next = null;
      this.tail = this.tail.prev ? this.tail.prev : null;
      return this.tail;

    } else {
      console.log(`There is no tail node.`);
    }
  }

  // removes a node from the middle of the linked list
  removeWhereN(n) {
    let currentNode = this.head;
    
    for (let i = 1; i < n; i++) {
      if (!currentNode) return console.log(`removeWhereN: There aren't that many nodes in this list yet...`);
      currentNode = currentNode.next;
    };
    
    currentNode.prev.next = currentNode.next;
    currentNode.next.prev = currentNode.prev;

    return currentNode;
  }

  print() {
    const list = [];
    let currentNode = this.head;

    while (currentNode) {
      list.push(currentNode.value);
      currentNode = currentNode.next;
    };

    console.log(`list:`, list);
    return list;
  };
};
