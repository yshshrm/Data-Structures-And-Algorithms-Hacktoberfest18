object Quicksort {
    def quicksort[T](cmp: (T,T) => Boolean, list: List[T]) : List[T] = {
        list match {
            case Nil =>
                Nil
            case pivot::tl =>
                val (e1, e2) = tl.partition( (X: T) => cmp(X, pivot) )
                quicksort(cmp, e1) ::: (pivot::Nil) ::: quicksort(cmp, e2)
        }
    }
}

