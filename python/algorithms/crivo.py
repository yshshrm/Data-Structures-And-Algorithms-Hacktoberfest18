MAX = 1000

primo = [True] * MAX
primo[0] = [False]
primo[1] = [False]
primos = []

for i in range(2, MAX):
	
	if primo[i]:
		
		for j in range(2*i, MAX, i):
			
			primo[j] = False
			
		primos.append(i)
