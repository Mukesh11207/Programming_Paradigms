#lang racket
(display "Enter coefficient of x^2 :- ")
(define a(read))

(display "Enter coefficient of x :- ")
(define b(read))

(display "Enter constant :- ")
(define c(read))

(define d (- (* b b) (* 4 a c)))
(cond ((> d 0)
      (display "Root 1 :- ")
      (display (/(+ (- b) (sqrt d))(* 2.0 a)))
      (display (newline))
      (display "Root 2 :- ")
      (display (/(- (- b) (sqrt d))(* 2.0 a)))
      (newline))
    ((= d 0)
    (display "equal root :- ")
    (display (/ (- b) (* 2.0 a)))
    (newline)
    )
    (else 
    (display "No real roots")
    (newline)
    )
)