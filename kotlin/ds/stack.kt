class Stack<T>{
    val items: MutableList<T> = mutableListOf()
    fun isEmpty() = items.isEmpty()
    fun count() = items.size
    fun push(item: T) = items.add(item)
    fun pop() : T? {
        val item = items.lastOrNull()
        if (!isEmpty()){
            items.removeAt(items.size -1)
        }
        return item
    }
    fun peek() : T? = items.lastOrNull()

    override fun toString(): String = items.toString()
}