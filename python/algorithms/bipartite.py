#This programs finds whether a graph is bipartite or not 
#A colour is assigned to each vertex
#Vertices on the same edge should not have the same colour

import sys
import queue
q = queue.Queue()

def bipartite(adj):
    
    color = [-1] * len(adj)
    visited = [False] * len(adj)
    #visited keeps a track of all the vertices beeing visited
    visited[0] = 1
    q.put(0)
    color[0] = 0
    while(not q.empty()):
        u = q.get()
        #Traversing connected vertices
        for v in range(len(adj[u])):
            if(not visited[adj[u][v]]):
                #Marking vertex as visited
                visited[adj[u][v]] = 1
                q.put(adj[u][v])
                #Checking if vertex has a colour
                if(color[adj[u][v]] == -1):
                    #Assigning a colour
                    color[adj[u][v]] = 1 - color[u]
                    
            #Vertex has the same colour as its parent vertex -> Non bipartite
            elif(color[adj[u][v]] == color[u]):                
                return 0
    
    return 1

#Reading the graph
#The first row contains no. of vertices and edges
#The other rows contain edges

#Example for non bipartite graph:
#4 4
#1 2
#1 3
#3 4
#2 4

#Example for bipartite graph:
#4 5
#1 2
#1 3
#3 4
#2 4
#1 4

    
input = sys.stdin.read()
data = list(map(int, input.split()))
n, m = data[0:2]
data = data[2:]
edges = list(zip(data[0:(2 * m):2], data[1:(2 * m):2]))
adj = [[] for _ in range(n)]
for (a, b) in edges:
    adj[a - 1].append(b - 1)
    adj[b - 1].append(a - 1)
#Prints bipartite if function returns 1 
if(bipartite(adj)):
    print("The graph is bipartite")
#Prints non-bipartite if function returns 0
else:
    print("The graph is not bipartite")

