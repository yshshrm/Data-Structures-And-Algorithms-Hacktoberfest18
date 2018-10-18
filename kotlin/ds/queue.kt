class Queue<T> {
    val items: MutableList<T> = mutableListOf()
    fun isEmpty() = items.isEmpty()
    fun count() = items.size
    fun enqueue(item: T) = items.add(item)
    fun dequeue() = if (!isEmpty()) items.removeAt(0) else null
    fun peek() = if (!isEmpty()) items[0] else null

    override fun toString(): String = items.toString()
}