#lang racket

(define (push elem lst) (if (null? elem)
                            lst
                            (append lst (list elem))))
(define (pop lst) (if (empty? lst)
                      '()
                      (cdr lst)))
(define (top lst) (if (empty? lst)
                      null
                      (car lst)))

;; tests
(push 4 '(1 42 0))
(pop '(1 2 3 4 5 6))
(top '(1 2 3 4 5))
(pop '())
(top '())

