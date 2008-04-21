(defpackage :cs430-project
  (:use :cl))

(in-package :cs430-project)

(defvar lst '(38 536 6345 8 91 103 1753))
(defvar nlst (loop for x from 9999 downto 0 collect x))
(defvar rlst (loop repeat 1000 collect (random 1000)))

(defun schar-aux (string index)
  (if (> (length string) index)
      (schar string index)
      #\0))

(defun radix-sort (list)
  (let* ((string-list (mapcar #'(lambda (x) (reverse (write-to-string x))) list))
	 (longest (loop for x in string-list maximize (length x))))
    (dotimes (i longest)
      (setq string-list (sort string-list
			      #'(lambda (x y) (char< (schar-aux x i) (schar-aux y i))))))
    (mapcar #'(lambda (x) (parse-integer (reverse x))) string-list)))

(defun quicksort (list)
  (when list
    (let ((pivot (car list)))
      (append
       (quicksort (remove-if-not #'(lambda (x) (<= x pivot)) (cdr list)))
       (list pivot)
       (quicksort (remove-if-not #'(lambda (x) (> x pivot)) (cdr list)))))))

(defun mergesort (list)
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