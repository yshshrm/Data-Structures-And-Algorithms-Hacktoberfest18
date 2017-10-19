public class DoublyLinkedList {

    private int size = 0;
    private Node head;
    private Node trailer;

    /**
     * initializing a Doubly Linked List.
     */
    public DoublyLinkedList() {
        head = new Node(null, trailer, null);
        trailer = new Node(null, null, head);
    }

    private class Node {
        /**
         * data value.
         */
        private Object data;
        /**
         * next & prev Nodes.
         */
        private Node next, prev;

        /**
         * initializing a node.
         * @param value a a
         * @param nextNode a
         * @param prevNode a
         */
        Node(final Object value,
             final Node nextNode, final Node prevNode) {
            data = value;
            next = nextNode;
            prev = prevNode;
        }

        /**
         * set next node for the the current one.
         * @param nextNode next
         */
        public void setNext(final Node nextNode) {
            next = nextNode;
        }
        /**
         * set previous node for the current one.
         * @param prevNode a
         */
        public void setPrev(final Node prevNode) {
            this.prev = prevNode;
        }

        /**
         * set value for the node.
         * @param value a
         */
        public void setValue(final Object value) {
            this.data = value;
        }

        /**
         * return the next node.
         * @return next
         */
        public Node getNext() {
            return next;
        }
        /**
         * return the previous node.
         * @return prev
         */
        public Node getPrev() {
            return prev;
        }

        /**
         * @return data
         */
        public Object getValue() {
            return data;
        }

    }

    public void add(final int index, final Object element) {
        if (index < 0 || index > size) {
            throw new RuntimeException("Invalid index.");
        }

        Node e = new Node(element, null, null);

        if (index == 0 && size == 0) {
            trailer.setPrev(e);
            e.setNext(trailer);
            e.setPrev(head);
            head.setNext(e);
        } else {
            Node p = head;
            for (int i = 0; i < index; i++) {
                p = p.getNext();
            }
            e.setPrev(p);
            e.setNext(p.getNext());
            p.getNext().setPrev(e);
            p.setNext(e);
        }

        size++;

    }

    public void add(final Object element) {
        Node e = new Node(element, trailer, trailer.getPrev());
        trailer.getPrev().setNext(e);
        trailer.setPrev(e);
        size++;
    }

    public Object get(final int index) {
        if (index < 0 || index >= size) {
            throw new RuntimeException("Invalid index.");
        }

        Node p = head;
        for (int i = 0; i <= index; i++) {
            p = p.getNext();
        }
        return p.getValue();
    }

    public void set(final int index, final Object element) {
        if (index < 0 || index >= size) {
            throw new RuntimeException("Invalid index.");
        }

        Node p = head;
        for (int i = 0; i <= index; i++) {
            p = p.getNext();
        }
        p.setValue(element);

    }

    public void clear() {
        head = new Node(null, trailer, null);
        trailer = new Node(null, null, head);
        size = 0;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public void remove(final int index) {
        if (index < 0 || index >= size) {
            throw new RuntimeException("Invalid index.");
        }

        Node p = head;
        for (int i = 0; i < index; i++) {
            p = p.getNext();
        }
        p.getNext().getNext().setPrev(p);
        p.setNext(p.getNext().getNext());
        size--;
    }

    public int size() {
        return size;
    }

    public DoublyLinkedList sublist(final int fromIndex, final int toIndex) {
        if (fromIndex < 0 || toIndex >= size || fromIndex > toIndex) {
            throw new RuntimeException("Invalid index.");
        }

        DoublyLinkedList list = new DoublyLinkedList();
        Node a = head;
        int i;
        for (i = 0; i <= fromIndex; i++) {
            a = a.getNext();
        }

        while (i <= toIndex + 1) {
            list.add(a.getValue());
            a = a.getNext();
            i++;
        }

        return list;
    }

    public boolean contains(final Object o) {
        Node p = head;
        int i = 0;
        while (i != size) {
            p = p.getNext();
            if (p.getValue().equals(o)) {
                return true;
            }
            i++;
        }
        return false;
    }

    public static void main(String[] args) {
        DoublyLinkedList doublyLinkedList = new DoublyLinkedList();
        doublyLinkedList.add(4);
        doublyLinkedList.add(5);
        doublyLinkedList.add(6);
        doublyLinkedList.add(1);
        doublyLinkedList.add(0);
        System.out.println(doublyLinkedList.get(4));
        System.out.println(doublyLinkedList.size());
    }
}
