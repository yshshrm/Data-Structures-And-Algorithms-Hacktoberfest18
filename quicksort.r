quickSort <- function(arr) {
  # Pick a number at random.
  mid <- sample(arr, 1)

  # Place-holders for left and right values.
  left <- c()
  right <- c()
  
  # Move all the smaller values to the left, bigger values to the right.
  lapply(arr[arr != mid], function(d) {
    if (d < mid) {
      left <<- c(left, d)
    }
    else {
      right <<- c(right, d)
    }
  })
  
  if (length(left) > 1) {
    left <- quickSort(left)
  }
  
  if (length(right) > 1) {
    right <- quickSort(right)
  }
