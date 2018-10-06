(define (insert n l cmp (ol '()))
  (cond
    [(empty? l)
     (append ol (list n))] ; or: (reverse (cons n (reverse ol)))
    [(not (cmp n (first l)))
     (append ol (list n) l)]
    [else (insert n
                  (rest l)
                  cmp
                  (append ol (list (first l))) ; or:  (reverse (cons (first l) (reverse ol)))
                  )] ))

(define (isort l cmp (sl '()))
  (cond
    [(empty? l) sl]
    [else (isort (rest l)
                 cmp
                 (insert (first l)
                         sl
                         cmp))] ))