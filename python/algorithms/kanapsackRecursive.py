def knapsack(objeto, capacidade):
	
	if objeto > qntdObjetos: return 0

	if dp[objeto][capacidade] != -1 : return dp[objeto][capacidade]
	
	else:
		
		#nao pegar o objeto
		dp[objeto][capacidade] = knapsack(objeto + 1, capacidade)
		
		#pegar o objeto
		if pesos[objeto] <= capacidade:
			
			dp[objeto][capacidade] = max(dp[objeto][capacidade], knapsack(objeto + 1, capacidade - pesos[objeto]) + valores[objeto])
	
	return dp[objeto][capacidade]
	

while True:
		
		try:
			
			qntdObjetos = int(raw_input())
			capacidade = int(raw_input())

			pesos = [0 for i in xrange(qntdObjetos + 1)]
			valores = [0 for i in xrange(qntdObjetos + 1)]
			dp = [[-1 for j in xrange(capacidade + 1)] for i in xrange(qntdObjetos + 1)]
			valores[0] = 0
			pesos[0] = 0

			for objeto in xrange(1,qntdObjetos + 1):
				
				valor, peso = map(int, raw_input().split())
				
				pesos[objeto] = peso
				valores[objeto] = valor

			knapsack(1,capacidade)

			print "%d" %dp[1][capacidade]
		
		except EOFError: break

	
