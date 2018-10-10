def kadane(lista):
	
	max_atual = 0
	max_total = -1
	
	for i in range(len(lista)):
		
		max_atual = max(max_atual + lista[i], lista[i])
		max_total = max(max_total, max_atual)

	if max_total < 0:
		
		max_total = 0

	return max_total

