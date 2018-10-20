class LinkedList{
    constructor() {
      this.head = null;
      this.tail = null;
      this.length = 0;
      this.Node = class {
        constructor(value) {
          this.value = value;
          this.next = null;
        }
      }
    }
    get list() {
      if (this.head) {
        const list = [this.head.value];
        let node = this.head.next;
        while(node) {
          list.push(`--> ${node.value}`);
          node = node.next;
        }
        return list.join('');
      } else {
        return "node list empty.";
			}
  
    }
  
    add(value) {
      const newNode = new this.Node(value);
      if (!this.head) {
        this.head = newNode;
        this.tail = newNode;
        this.length += 1;
      } else {
        let node = this.head;
        while(true){
          if (node.next === null) {
            node.next = newNode;
            this.tail = newNode;
            this.length += 1;
            break;
          } else node = node.next;
        }
      }
    }
  }