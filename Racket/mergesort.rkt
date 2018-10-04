(define (merge-lists xs ys)
  (cond
    [(null? xs) ys]
    ;if xs is empty, return ys
    [(null? ys) xs]
    ;if ys is empty, return xs
    [(< (car xs) (car ys))
    ;if the head of list "xs" is bigger than head of list "ys"
     (cons (car xs) (merge-lists (cdr xs) ys))]
     ;cons head xs to (recurse)
    [#t ;I use true as an else cond here - possibly bad style?
     (cons (car ys) (merge-lists xs (cdr ys)))]))