#lang racket
(require htdp/testing)

(define (quick-sort l)
  (cond
   [(empty? l) empty]
   [else (append (quick-sort (smaller (first l) (rest l)))
                 (list (first l))
                 (quick-sort (larger (first l) (rest l))))]))


(define (smaller x l)
  (filter (lambda (y) (< y x)) l))

(define (larger x l)
  (filter (lambda (y) (>= y x)) l))


(check-expect (quick-sort (list 3 3 2 12 11)) (list 2 3 3 11 12))