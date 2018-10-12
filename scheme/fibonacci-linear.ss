(define (fibonacci-linear n)
	(define (fibonacci-iter index last-num current-num)
		(if (= index 0)
			current-num
			(fibonacci-iter (- index 1) current-num (+ last-num current-num))))
	(if (<= n 2)
		1
		(fibonacci-iter (- n 2) 1 1)))

