/* Ascending order Binomial Heap, implemented with help of Cormen */

function BinomialHeap(node) {
  this.head = node;
}

function Node(val) {
  this.next = null;
  this.child = null;
  this.parent = null;
  this.sibling = null;
  this.degree = 0;
  this.val = val;
}

/* Adding single values is done by creating a one-node Binomial Heap and merging it with the original one */
BinomialHeap.prototype.add = function(val) {
	let heap = new BinomialHeap;
	let node = new Node(val);
	heap.head = node;
	node.sibling = node.parent = node.child = null;
	node.degree = 0;
	this.merge(heap);
}

/* Merges and sorts two heaps together. In Binomial Heaps there can't be two child heaps with the same degree. */
BinomialHeap.prototype.merge = function(addedHeap) {
	if (addedHeap === null){
		return; 
	}
	this.addHeap(addedHeap); 
	// After adding two heaps together, we must check if there are not child heaps with the same degree.
	let node = this.head, previous = null, next = null, temp = null;
	while (node.sibling !== null){ 										// By checking the heads' list 
		if (node.degree !== node.sibling.degree){				// we make sure there're no two 
			previous = node;															// heaps with same degree.
			node = node.sibling;
		}	else {
			if (node.sibling.sibling === null){						//if the next sibling is the last one
				if(node.val > node.sibling.val){
					temp = node.sibling.sibling;
					this.treeLink(node.sibling, node);
					node.sibling = temp;
				} else {
					if (previous !== null) {
						previous.sibling = node.sibling;
					} else {
						this.head = node.sibling;
					}
					next = node.sibling;
					this.treeLink(node, node.sibling);
					node = next;
				}
			} else if (node.sibling.sibling !== null && node.sibling.sibling.degree !== node.degree){
				if (node.val > node.sibling.val) {						//if the next sibling is not the last
					temp = node.sibling.sibling;								//we must check whether the one after him
					this.treeLink(node.sibling, node);					//doesn't also have the same degree
					node.sibling = temp;												//This may happen due to merging smaller heaps. 
				} else {
					if (previous !== null) {
						previous.sibling = node.sibling;
					} else {
						this.head = node.sibling;
					}
					next = node.sibling;
					this.treeLink(node, node.sibling);
					node = next;
				}
			} else {
				previous = node;
				node = node.sibling;
			}
		}
	}
}

/* Adds two heaps together while keeping the order of heads' list degrees as not-descending*/
BinomialHeap.prototype.addHeap = function(addedHeap) {
	let originalHeapHead = this.head;
	let addedHeapHead = addedHeap.head;
	let temp1 = null, temp2 = null;
	if (originalHeapHead === null){
		this.head = addedHeapHead;
		return;
	}
	while (addedHeap.head !== null){
		addedHeapHead = addedHeap.head;
		while(originalHeapHead.sibling !== null && originalHeapHead.sibling.degree < addedHeapHead.degree) {
			originalHeapHead = originalHeapHead.sibling;
		}
		if (originalHeapHead.degree < addedHeapHead.degree){
			temp1 = originalHeapHead.sibling;
			temp2 = addedHeap.head.sibling;
			originalHeapHead.sibling = addedHeapHead;
			originalHeapHead.sibling.sibling = temp1;
			addedHeap.head = temp2;
		} else {
			temp1 = this.head;
			temp2 = addedHeap.head;
			addedHeap.head = addedHeap.head.sibling;
			temp2.sibling = temp1;
			this.head = temp2;
			originalHeapHead = addedHeapHead;
			addedHeapHead = addedHeap.head;
		}
	}
};

/* Connects two heaps of the same degree into one with incremented degree */
BinomialHeap.prototype.treeLink = function(newSon, newParent) {
	newSon.parent = newParent;
	newSon.sibling = newParent.child;
	newParent.child = newSon;
	newParent.degree = newParent.degree + 1;
}