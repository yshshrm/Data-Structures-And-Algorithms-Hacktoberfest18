G =    [[0,1,4,0,0],
		[0,0,2,5,12],
		[0,0,0,2,0],
		[0,0,0,0,3],
		[0,0,0,0,0]]

h = [7,6,2,1,0]
f = [7,-1,-1,-1,-1]
g = [0,0,0,0,0]
parent = [-1,-1,-1,-1,-1]
open = [0] 
closed = []
goal = 4

def A_star():
	while open != []:
		min = 100
		for i in open:
			if min > f[i] and f[i] > -1:
				min = f[i]
				n = i

		closed.append(n)
		open.remove(n)

		if goal == n:
			return f[4], parent

		else:
			successor = []

			for j in range(5):
				if(G[n][j] > 0):
					successor.append(j)

			for m in successor :
				if(m not in open and m not in closed):
					g[m] = g[n] + G[n][m]
					f[m] = g[m] + h[m]
					open.append(m)
					parent[m] = n
				
				elif(m in open):
					if(g[m] > g[n] + G[n][m]):
						g[m] = g[n] + G[n][m]
						parent[m] = n
						f[m] = g[m] + h[m]

				else:
					if(g[m] > g[n] + G[n][m]):
						g[m] = g[n] + G[n][m]
						parent[m] = n
						f[m] = g[m] + h[m]  
						for j in range(5):
							if(G[m][j]>0):
								if(g[j] > g[m] + G[m][j]) :
									g[j] = g[m] + G[m][j]
									f[j] = g[j] + h[j]


path_length,parent = A_star()

path = []
i = 4
while(i != 0):
	path.append(i)
	i = parent[i]

path.append(0)

print("Path: ",path[::-1])  
print("Path length:",path_length)
