class Graph:

    def __init__(self,vertices):
        self.V=len(vertices)
        self.graph={v:[] for v in vertices}
    
    def addedge(self,x,y):
        self.graph[x].append(y)

    def is_there_back_edge(self,node,visited,recStack):

        visited[node]=True
        recStack[node]=True

        for neighbour in self.graph[node]:
            if(visited[neighbour]==False):
                if(self.is_there_back_edge(neighbour, visited, recStack)==True):
                    return True
            elif recStack[neighbour]==True:
                return True
        recStack[node]=False
        return False

    def is_Cycle(self):
        visited=[False]*self.V
        recStack=[False]*self.V

        for node in range(self.V):
            if(visited[node]==False):
                if(self.is_there_back_edge(node, visited, recStack)):
                    return True
        return False

e=int(input("Enter no. of edges "))
v=int(input("Enter no. of vertices :: "))
vertices=[]
for i in range(v):
    vertices.append(i)

g=Graph(vertices)

print("Now, enter edges in form of src - > dest. :: ")
for i in range(e):
    x=int(input("Enter src. :: "))
    y=int(input("Enter dest. :: "))
    g.addedge(x, y)

if(g.is_Cycle()):
    print("Graph has a cycle ")
else:
    print("Graph has no cycles ")
                 
            