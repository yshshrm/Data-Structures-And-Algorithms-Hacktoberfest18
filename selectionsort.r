selectionSort <- function(arr) {
  # Find the smallest value in the list (ok sort of cheating, because we're using the highliy optimized min() function).
  smallest <- min(arr)
  rest <- arr[arr != smallest]
  
  if (length(rest) > 1) {
    rest <- selectionSort(arr[arr != smallest])
  }
  
  c(smallest, rest)
}
