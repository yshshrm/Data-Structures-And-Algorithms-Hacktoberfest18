class LinkedList<T>() {
    private data class Node<T>(val value: T, var next: Node<T>? = null) {
        fun hasNext() : Boolean {
            return next != null
        }
    }

    private var root: Node<T>? = null

    fun isEmpty() : Boolean {
        return root == null
    }

    fun size() : Int {
        if (isEmpty()) return 0;
        var current = root
        var count = 0;
        while (current != null) {
            count += 1
            current = current.next
        }
        return count
    }

    fun add(value: T) {
        if (isEmpty()) root = Node(value)
        else {
            var current = root
            while (current!!.hasNext()) {
                current = current.next
            }
            current.next = Node(value)
        }
    }

    fun get(index: Int) : T {
        return getNode(index)?.value ?: throw IndexOutOfBoundsException()
    }

    fun remove(index: Int) : T {
        if (isEmpty()) throw IndexOutOfBoundsException()
        if (index == 0) {
            val rootValue = root!!.value
            root = root?.let { it.next }
            return rootValue
        }
        val nodeBeforeRemoval: Node<T>? = getNode(index - 1)
        var nodeToRemove: Node<T> = nodeBeforeRemoval?.next ?: throw IndexOutOfBoundsException()
        nodeToRemove.next?.let {
            nodeBeforeRemoval.next = it
        } ?: run { nodeBeforeRemoval.next = null }
        return nodeToRemove.value
    }

    private fun getNode(index: Int): Node<T>? {
        if (isEmpty()) return null
        var current = root
        var count = 0
        while (count < index) {
            current = current?.next ?: return null
            count += 1
        }
        return current
    }
}