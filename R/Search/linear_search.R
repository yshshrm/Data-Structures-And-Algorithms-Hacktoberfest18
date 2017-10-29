# Linear Search in R

linear_search <- function(vec, num){
	for (i in vec){
		if (i == num)
			return(TRUE)
	}
	return(FALSE)
}

ans = linear_search( c(1:10), 7 )

ifelse(ans == TRUE, "Number found in vector", "Number not found in vector")