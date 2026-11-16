#lang racket
(define a '(10 20 30))
(display (car a))
(newline)
(display (cons 5 '(a)))
(newline)
(display '(+ 10 a))
(newline)

(display(number? (car a)))
(newline)
(define c "hi")
(display (string? c))