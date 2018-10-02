public class SinglyLinkedList {

    private class Node {
        private Object value;
        private Node next;

        Node(final Object o) {
            value = o;
            next = null;
        }

        public Object getValue() {
            return value;
        }

        public void setValue(final Object o) {
            value = o;
        }

        public Node getNext() {
            return next;
        }

        public void setNext(final Node n) {
            next = n;
        }
    }

    private Node head = null;

    private int size = 0;

    public void add(final int index, final Object element) {

        if (index > size || index < 0) {
            throw new RuntimeException("Invalid index.");
        }

        Node e = new Node(element);

        if (index == 0) {
            e.setNext(head);
            head = e;
        } else {

            Node a = head;
            for (int i = 0; i < index - 1; i++) {
                a = a.getNext();
            }

            e.setNext(a.getNext());
            a.setNext(e);
        }
        size++;
    }

    public void add(final Object element) {

        Node e = new Node(element);

        if (size == 0) {
            head = e;
        } else {
            Node a = head;
            while (a.getNext() != null) {
                a = a.getNext();
            }

            a.setNext(e);
        }
        size++;
    }

    public Object get(final int index) {

        if (index >= size || index < 0) {
            throw new RuntimeException("Invalid index.");
        }

        Node a = head;
        for (int i = 0; i < index; i++) {
            a = a.getNext();
        }
        return a.getValue();
    }

    public void set(final int index, final Object element) {

        if (index >= size || index < 0) {
            throw new RuntimeException("Invalid index.");
        }

        Node a = head;
        for (int i = 0; i < index; i++) {
            a = a.getNext();
        }
        a.setValue(element);
    }

    public void clear() {
        head = null;
        size = 0;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public void remove(final int index) {

        if (index >= size || index < 0) {
            throw new RuntimeException("Invalid index.");
        }

        if (index == 0) {
            head = head.getNext();
        } else {
            Node a = head;
            for (int i = 0; i < index - 1; i++) {
                a = a.getNext();
            }

            a.setNext(a.getNext().getNext());
        }
        size--;
    }

    public int size() {
        return size;
    }

    public SinglyLinkedList sublist(final int fromIndex, final int toIndex) {

        if (fromIndex < 0 || toIndex >= size || fromIndex > toIndex) {
            throw new RuntimeException("Invalid index.");
        }

        SinglyLinkedList list = new SinglyLinkedList();
        Node a = head;
        int i;
        for (i = 0; i < fromIndex; i++) {
            a = a.getNext();
        }

        while (i <= toIndex) {
            list.add(a.getValue());
            a = a.getNext();
            i++;
        }

        return list;
    }

    public boolean contains(final Object o) {

        Node a = head;
        while (a != null) {
            if (a.getValue().equals(o)) {
                return true;
            }
            a = a.getNext();
        }
        return false;
    }

    public static void main(String[] args) {
        SinglyLinkedList singlyLinkedList = new SinglyLinkedList();
        singlyLinkedList.add(3);
        System.out.println(singlyLinkedList.contains(3));
        System.out.println(singlyLinkedList.size());
        singlyLinkedList.clear();
        System.out.println(singlyLinkedList.size());
    }

}
