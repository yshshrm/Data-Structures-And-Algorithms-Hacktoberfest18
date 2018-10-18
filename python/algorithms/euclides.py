def MDC(a,b):
	
	while a % b != 0:
		
		aux = b
		
		b = a  % b
		
		a = aux
		
	return b
