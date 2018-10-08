(defvar a (make-array '10))
(dotimes (i 10)
  (setf (aref a i) (+ i 1)))
(write a)
