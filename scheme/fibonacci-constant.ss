; note: breaks when n > 70 because of non-finite precision for sqrt(5)

(define golden-ratio 
	(/ (+ 1 (sqrt 5)) 2))

(define (fibonacci-constant n)
	(inexact->exact 
		(floor (+ 0.5 (/ (expt golden-ratio n) (sqrt 5))))))

