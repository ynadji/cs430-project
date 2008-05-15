(defpackage :cs430-project
  (:use :cl)
  (:export #:run-all-tests))

(in-package :cs430-project)

(load "/Users/ynadji/Documents/Homework/cs430/project/lists.lisp")

(defun schar-aux (string index)
  (if (> (length string) index)
      (schar string index)
      #\0))

(defun radix-sort (list)
  "Radix Sort using Least Significant Digit. Timesink due to string conversion crap
  unfortunately, it's how Bill did it, so I'm not sure I want to go back and change
  everything and make him do the same thing. Ugly"
  (let* ((string-list (mapcar #'(lambda (x) (reverse (write-to-string x))) list))
	 (longest (loop for x in string-list maximize (length x))))
    (dotimes (i longest)
      (setq string-list (sort string-list
			      #'(lambda (x y) (char< (schar-aux x i) (schar-aux y i))))))
    (mapcar #'(lambda (x) (parse-integer (reverse x))) string-list)))

(defun quicksort (list)
  "Your typical, pretty quicksort in X-functional language. Pretty much rules
  thanks to remove-if-not."
  (when list
    (let ((pivot (car list)))
      (append
       (quicksort (remove-if-not #'(lambda (x) (<= x pivot)) (cdr list)))
       (list pivot)
       (quicksort (remove-if-not #'(lambda (x) (> x pivot)) (cdr list)))))))

(defun mergesort (list)
  "Mergesort, also hella pretty mostly due to the split helper function"
  (if (<= (length list) 1)
      list
      (multiple-value-bind (left right) (split list)
	(merge 'list
	       (mergesort left) (mergesort right) #'<))))

(defun split (list)
  (loop for x in list with y = 1
     if (evenp y)
     collect x into l
     else
     collect x into r
     do (incf y)
     finally (return (values l r))))

(defun bubble-sort (list)
  (loop for i from 0 to (- (length list) 2)
     do (loop for j from (+ 1 i) to (- (length list) 1)
	     do (when (> (nth i list) (nth j list)) (rotatef (nth i list) (nth j list)))))
  list)
	    

(defun swap (list i j)
  (let ((i-val (nth i list)))
    (setf (nth i list) (nth j list))
    (setf (nth j list) i-val)))

(defun run-test (list sort)
  (let ((start 0)
	(end 0)
	(sum 0))
    (dotimes (i 3)
      (setq start (get-internal-real-time))
      (funcall sort list)
      (setq end (get-internal-real-time))
      (incf sum (- end start)))
    (float (/ sum 3))))

(defun run-all-tests ()
  (loop for list-name in *test-lists*
     for list = (eval list-name)
     for qsort-time = (run-test list #'quicksort)
     for merge-time = (run-test list #'mergesort)
     for radix-time = (run-test list #'radix-sort)
     for bubbl-time = (run-test list #'bubble-sort)
     do (format t "Test Name: ~s~%~%Quicksort: ~d ms~%Mergesort: ~d ms~%Radixsort: ~d ms~%Bubblesort: ~d ms~%~%"
		list-name
		qsort-time
		merge-time
		radix-time
		bubbl-time)))
