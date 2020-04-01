class Graph:
    def __init__(self,v):
        self.V=v
        self.graph={new_list:[] for new_list in range(v)}

    def addedge(self,u,v):
        self.graph[u].append(v)
    
    def topologicalSort(self,visited,stack,v):
        visited[v]=True

        for i in self.graph[v]:
            if(visited[i]==False):
                self.topologicalSort(visited, stack, i)
        
        stack.insert(0, v)
    def TSort(self):
        visited=[False]*self.V

        stack=[]

        for i in range(self.V):
            if(visited[i]==False):
                self.topologicalSort(visited, stack, i)

        print( stack)


e=int(input("Enter no of edgs :: "))
v=int(input("Enter no of vertices :: "))

g=Graph(v)

print("Now, enter edges :: ")

for i in range(e):
    print()
    u=int(input("Enter src :: "))
    v=int(input("Enter dest :: "))
    g.addedge(u,v)

g.TSort()
