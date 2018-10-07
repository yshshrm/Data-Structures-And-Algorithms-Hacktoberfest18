def createAdjMatrix(V, G):  
  
  adjMatrix = []
  
  for i in range(0, V):
    adjMatrix.append([])
    for j in range(0, V):
      adjMatrix[i].append(0)
      
  for i in range(0, len(G)):
    adjMatrix[G[i][0]][G[i][1]] = G[i][2]
    adjMatrix[G[i][1]][G[i][0]] = G[i][2]
    
  return adjMatrix

def prims(V, G):
  
  adjMatrix = createAdjMatrix(V, G)
  vertex = 0
  MST = []
  edges = []
  visited = []
  minEdge = [None,None,float('inf')]

  while len(MST) != V-1:
    visited.append(vertex)
    
    for r in range(0, V):
      if adjMatrix[vertex][r] != 0:
        edges.append([vertex,r,adjMatrix[vertex][r]])

    for e in range(0, len(edges)):
      if edges[e][2] < minEdge[2] and edges[e][1] not in visited:
        minEdge = edges[e]
        
    edges.remove(minEdge)
    MST.append(minEdge)
    vertex = minEdge[1]
    minEdge = [None,None,float('inf')]
    
  return MST
  
a, b, c, d, e, f = 0, 1, 2, 3, 4, 5

graph = [
  [a,b,2],
  [a,c,3],
  [b,d,3],
  [b,c,5],
  [b,e,4],
  [c,e,4],
  [d,e,2],
  [d,f,3],
  [e,f,5]
]

print(prims(6, graph))